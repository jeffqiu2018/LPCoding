#ifndef HANNING
#define HANNING

#include <IWindow.h>
#include <cmath>

/**
 * @brief Implementation of IWindow strategy pattern interface using Hanning windowing function
 * See: http://en.wikipedia.org/wiki/Window_function for details
 *
 */
class Hanning : public IWindow
{
public:
    /**
     * @brief evaluate Hamming function
     * @param i - position of sample in currently processed window
     * @param size - size of the currently processed window
     * @return value of window function for i-th sample in window with [size] number of samples
     */
    double evaluate(unsigned i, unsigned size)
	{
		return 0.5*(1 - cos((2*sample*PI)/(size-1)));
	}
};

#endif
