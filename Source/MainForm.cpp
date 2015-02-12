#include <MainForm.h>

#include <QFileDialog>
#include <Hanning.h>
#include <Hamming.h>
#include <iostream>

using namespace std;

MainForm::MainForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_wave_view = new QCustomPlot;
	ui.waveLayout->addWidget(m_wave_view);
	m_wave_view->addGraph();
	m_wave_view->xAxis->setLabel("Sample");
	m_wave_view->yAxis->setLabel("Value");

	m_pred_view = new QCustomPlot;
	ui.predLayout->addWidget(m_pred_view);
	m_pred_view->addGraph();
	m_pred_view->xAxis->setLabel("Sample");
	m_pred_view->yAxis->setLabel("Value");

	m_dist_view = new QCustomPlot;
	ui.distLayout->addWidget(m_dist_view);
	m_dist_view->addGraph();
	m_dist_view->xAxis->setLabel("Frame");
	m_dist_view->yAxis->setLabel("Distance");

	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(open()));
	connect(ui.processBtn, SIGNAL(clicked()), this, SLOT(process()));
	connect(ui.actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));
	connect(ui.winfCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(setWindow()));
	connect(ui.widthEdit, SIGNAL(editingFinished()), this, SLOT(setWinWidth()));
	connect(ui.vecwidthEdit, SIGNAL(editingFinished()), this, SLOT(setVecWidth()));

	connect(ui.timeScroll, SIGNAL(valueChanged(int)), this, SLOT(timeScrollChanged(int)));

	m_model = nullptr;
}

MainForm::~MainForm()
{
	if (m_model)
		delete m_model;
	if (m_wave_view)
		delete m_wave_view;
	if (m_pred_view)
		delete m_pred_view;
	if (m_dist_view)
		delete m_dist_view;
}

void MainForm::open()
{
	QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Wav files (*.wav)"));
	if (file_name != "")
	{
		if (m_model)
			delete m_model;
		m_model = new Model(file_name.toStdString());

        string std_fname = file_name;
        unsigned i = std_fname.size() - 1;
        while(std_fname[i] != '\\' || std_fname[i] != '/')
            i--;
        QString f_name = std_fname.substr(i+1, std_fname.size()-i-1);
        ui.filenameLabel->setText(f_name);
		ui.samplerateLabel->setText(QString::number(m_model->get_wav_model().get_sample_rate()) + " Hz");
		ui.byterateLabel->setText(QString::number(m_model->get_wav_model().get_byte_rate()) + " B/s");
		ui.bpsLabel->setText(QString::number(m_model->get_wav_model().get_bps()) + " bits/sample");
		ui.durationLabel->setText(QString::number(m_model->get_wav_model().get_duration()) + " sec");

		ui.winfCombo->clear();
		ui.winfCombo->insertItem(0, "Hanning");
		ui.winfCombo->insertItem(1, "Hamming");
		ui.winfCombo->setCurrentIndex(0);

		ui.widthEdit->setText(QString::number(m_model->get_window_width()));
		ui.vecwidthEdit->setText(QString::number(m_model->get_vector_width()));
		
		ui.setupBox->setEnabled(true);
		ui.processBtn->setEnabled(true);

		unsigned sample_rate = m_model->get_wav_model().get_sample_rate();
		unsigned sample_num = m_model->get_wav_model().get_sample_num();
		m_width = sample_rate;

		double ratio = static_cast<double>(sample_rate) / sample_num;
		
		ui.timeScroll->setPageStep(sample_num*ratio);
		ui.timeScroll->setValue(0);
		ui.timeScroll->setMaximum(sample_num - ui.timeScroll->pageStep());
		ui.timeScroll->setEnabled(true);

		int max_samp = INT_MIN;
		int min_samp = INT_MAX;
		QVector<double> x(sample_num), y(sample_num);
		for (unsigned i = 0; i < sample_num; i++)
		{
			x[i] = i; 
			y[i] = m_model->get_wav_model().get_channel(0)[i];
			if (y[i] > max_samp) max_samp = y[i];
			if (y[i] < min_samp) min_samp = y[i];
		}
		
		m_wave_view->graph(0)->setData(x, y);
		m_wave_view->xAxis->setRange(0, sample_rate);
		m_wave_view->yAxis->setRange(1.1*min_samp, 1.1*max_samp);

		m_wave_view->axisRect()->setupFullAxesBox(true);
		m_wave_view->setInteractions(QCP::iRangeZoom);
		m_wave_view->replot();
	}
}

void MainForm::process()
{
	m_model->processInput();

	ui.processBtn->setEnabled(false);

	ui.timeScroll->setValue(0);
	
	unsigned sample_rate = m_model->get_wav_model().get_sample_rate();
	unsigned sample_num = m_model->get_wav_model().get_sample_num();

	int max_samp = INT_MIN;
	int min_samp = INT_MAX;
	QVector<double> x(sample_num), y(sample_num);
	for (unsigned i = 0; i < sample_num; i++)
	{
		x[i] = i;
		y[i] = m_model->get_predicted()[i];
		if (y[i] > max_samp) max_samp = y[i];
		if (y[i] < min_samp) min_samp = y[i];
	}

	m_pred_view->graph(0)->setData(x, y);
	m_pred_view->xAxis->setRange(0, sample_rate);
	m_pred_view->yAxis->setRange(1.1*min_samp, 1.1*max_samp);

	m_pred_view->axisRect()->setupFullAxesBox(true);
	m_pred_view->setInteractions(QCP::iRangeZoom);
	m_pred_view->replot();

	min_samp = INT_MAX;
	max_samp = INT_MIN;
	unsigned feature_size = m_model->get_features().size();
	QVector<double> x1(feature_size);
	QVector<double> y1(feature_size);
	y1[0] = 0.0;
	for (unsigned i = 1; i < feature_size; i++)
	{
		x1[i] = i;
		Vector dist = m_model->get_features()[i] - m_model->get_features()[i - 1];
		y1[i] = dist.len();
		if (y1[i] > max_samp) max_samp = y1[i];
		if (y1[i] < min_samp) min_samp = y1[i];
	}

	unsigned frames_per_second = 1000 / m_model->get_window_width();
	m_dist_view->graph(0)->setData(x1, y1);
	m_dist_view->xAxis->setRange(0, frames_per_second);
	m_dist_view->yAxis->setRange(1.1*min_samp, 1.1*max_samp);
	m_dist_view->axisRect()->setupFullAxesBox(true);
	m_dist_view->setInteractions(QCP::iRangeZoom);
	m_dist_view->replot();
}

void MainForm::setWindow()
{
	QString winF = ui.winfCombo->currentText();
	if (winF == "Hamming")
		m_model->set_window(new Hamming());
	else if (winF == "Hanning")
		m_model->set_window(new Hanning());
	ui.processBtn->setEnabled(true);
}

void MainForm::setWinWidth()
{
	unsigned win_width = ui.widthEdit->text().toUInt();
	if (win_width < 10 || win_width > 100)
	{
		win_width = 20;
		ui.widthEdit->setText(QString::number(win_width));
	}
	m_model->set_window_width(win_width);
	ui.processBtn->setEnabled(true);
}

void MainForm::setVecWidth()
{
	unsigned vec_width = ui.vecwidthEdit->text().toUInt();
	if (vec_width < 1 || vec_width > 30)
	{
		vec_width = 12;
		ui.vecwidthEdit->setText(QString::number(vec_width));
	}
	m_model->set_vector_width(vec_width);
	ui.processBtn->setEnabled(true);
}

void MainForm::timeScrollChanged(int value)
{
	if (qAbs(m_wave_view->xAxis->range().center() - value) > 0.01) 
	{
		m_wave_view->xAxis->setRange(value, m_wave_view->xAxis->range().size(), Qt::AlignLeft);
		m_pred_view->xAxis->setRange(value, m_pred_view->xAxis->range().size(), Qt::AlignLeft);
		unsigned frame_width = (m_model->get_wav_model().get_sample_rate() / 1000) * m_model->get_window_width();
		unsigned value_to_frame_num = value / frame_width;
		m_dist_view->xAxis->setRange(value_to_frame_num, m_dist_view->xAxis->range().size(), Qt::AlignLeft);
		m_wave_view->replot();
		m_pred_view->replot();
		m_dist_view->replot();
	}
}
