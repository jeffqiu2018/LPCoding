#ifndef IWINDOW
#define IWINDOW

const double PI = 3.14159;

/**
 * @brief The Window function Strategy pattern interface
 * See: http://en.wikipedia.org/wiki/Window_function for details
 */
class IWindow
{
public: 
    /**
     * @brief evaluate window function
     * @param i - position of sample in currently processed window
     * @param size - size of the currently processed window
     * @return value of window function for i-th sample in window with [size] number of samples
     */
    virtual double evaluate(unsigned i, unsigned size) = 0;
};

#endif
