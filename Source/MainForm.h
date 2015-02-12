#ifndef MAIN_FORM
#define MAIN_FORM

#include <QtWidgets/QMainWindow>
#include "ui_MainForm.h"
#include <Model.h>
#include <qcustomplot.h>

/**
 * @brief Main class of the application. It holds all other components of system.
 */
class MainForm : public QMainWindow
{
	Q_OBJECT

public:
    /**
     * @brief MainForm constructor
     * @param parent - GUI parent of this frame
     */
	MainForm(QWidget *parent = 0);

    /**
     * @brief Destructor
     */
	~MainForm();

private slots:

    /**
     * @brief Handler for File->Open which opens wav file
     */
	void open();

    /**
     * @brief Handler for Process
     */
	void process();
	void setWindow();
	void setWinWidth();
	void setVecWidth();
	void timeScrollChanged(int val);

private:
	Model *m_model;
	QCustomPlot *m_wave_view;
	QCustomPlot *m_pred_view;
	QCustomPlot *m_dist_view;

	unsigned m_width;

	Ui::MainWindow ui;
};

#endif
