#ifndef MODEL
#define MODEL

#include <string>
#include <WavModel.h>
#include <IWindow.h>
#include <Vector.h>

class Model
{
public:
    /**
     * @brief Model constructor
     * @param file_name - path to the .wav file we wish to open
     */
	Model(std::string &file_name);

    /**
     * @brief Destructor
     */
	~Model() { if (m_window) delete m_window; }

    /**
     * @brief Process model's data and calculate feature vectors
     */
	void processInput();

    /**
     * @brief Getter for window width
     * @return Width of the window
     */
	unsigned	get_window_width() { return m_window_width; }

    /**
     * @brief Getter for dimension of the feature vectors
     * @return Dimension of the feature vectors
     */
	unsigned	get_vector_width() { return m_vector_width; }

    /**
     * @brief Getter for model of the wav file currently loaded
     * @return Reference to the model of the wav file currently loaded
     */
	WavModel&	get_wav_model() { return m_wav_model; }

    /**
     * @brief Getter for collection(std::vector) of the feature vectors
     * @return All feature vectors
     */
	std::vector<Vector>& get_features() { return m_features; }

    /**
     * @brief Getter for the predicted feature vectors using LPC
     * @return Predicted feature vectors using LPC
     */
	std::vector<double>& get_predicted() { return m_predicted; }

    /**
     * @brief Set window function
     * @param window - pointer to the class which implements window function (Hanning of Hamming)
     */
	void set_window(IWindow *window) { if (m_window) delete m_window; m_window = window; }

    /**
     * @brief Set window width
     * @param new_width - new width of the window
     */
    void set_window_width(unsigned new_width) { m_window_width = new_width; }

    /**
     * @brief Set feature vector dimension
     * @param new_width - new dimension of the feature vector
     */
	void set_vector_width(unsigned new_width) { m_vector_width = new_width; }
private:

    /**
     * @brief Util function which calculate feature vecotr for the current window
     * @param data - samples of the current window we processing
     * @param width - width of the current window
     * @return Feature vector which represents current window
     */
	Vector calculateCoeff(short *data, unsigned width);

    /**
     * @brief Pointer to the current window function in use
     */
	IWindow *m_window;

    /**
     * @brief Wav model (Wav data)
     */
	WavModel m_wav_model;

    /**
     * @brief All feature vectors for current wav model
     */
	std::vector<Vector> m_features;

    /**
     * @brief All predicted vectors for current wav model
     */
	std::vector<double> m_predicted;

    /**
     * @brief Width of the window
     */
	unsigned m_window_width;

    /**
     * @brief Dimension of the feature vector
     */
	unsigned m_vector_width;
};

#endif

