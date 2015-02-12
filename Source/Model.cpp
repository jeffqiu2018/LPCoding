#include <Model.h>
#include <Hanning.h>
#include <fstream>

using namespace std;

Model::Model(string &file_name)
{
	ifstream ifs(file_name, ios::binary);
	
	ifs >> m_wav_model;
	m_window = new Hanning();
	m_window_width = 20;
	m_vector_width = 12;

	ifs.close();
}

void Model::processInput()
{
	unsigned window_size = (m_wav_model.get_sample_rate() / 1000)*m_window_width;
	unsigned sample_num = m_wav_model.get_sample_num();
	unsigned num_windows = ceil(static_cast<double>(sample_num) / window_size);

	short *window = new short[window_size];

	m_predicted = vector<double>(sample_num, 0.0);
	m_features.clear();
	for (unsigned win = 0; win<sample_num; win += window_size)
	{
		unsigned j;
		for (j = 0; j + win < sample_num && j < window_size; j++)
			window[j] = m_wav_model.get_channel(0)[j + win] * m_window->evaluate(j, window_size);


		Vector coeff = calculateCoeff(window, j);
		m_features.push_back(coeff);
		for (j = m_vector_width; j + win < sample_num && j < window_size; j++)
		{
			for (unsigned k = 0; k < m_vector_width; k++)
			{
				double c = coeff[k];
				double w = window[j-k-1];
				m_predicted[j + win] -= c*w; 
			}
		}
	}	
	delete window;
}

Vector Model::calculateCoeff(short *window, unsigned width)
{
	vector<double> r(m_vector_width+1, 0.0);
	for (unsigned p = 0; p <= m_vector_width; p++)
		for (unsigned n = 0; n <= width - p - 1; n++)
			r[p] += static_cast<double>(window[n]) * window[n + p];

	//LEVINSON-DURBIN REKUZRIJA
	//"Speech Processing" knjiga na materijalima
	vector<double> coeff(m_vector_width + 1, 0.0);
	coeff[0] = 1.0;
	double error = r[0];

	for (unsigned k = 0; k < m_vector_width; k++)
	{
		double lambda = 0.0;
		for (unsigned j = 0; j <= k; j++)
			lambda -= coeff[j] * r[k + 1 - j];
		lambda /= error;

		for (unsigned n = 0; n <= (k + 1) / 2; n++)
		{
			double temp = coeff[k + 1 - n] + lambda*coeff[n];
			coeff[n] = coeff[n] + lambda*coeff[k + 1 - n];
			coeff[k + 1 - n] = temp;
		}
		error *= 1.0 - lambda*lambda;
	}

	return Vector(++coeff.begin(), coeff.end());
}
