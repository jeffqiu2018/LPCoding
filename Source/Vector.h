#ifndef VECTOR
#define VECTOR

#include <vector>
#include <cmath>

/**
 * @brief The n-dimensional Vector class
 */
class Vector
{
public:
    /**
     * @brief Constructor with std::vector<double> type
     * @param init - vector which hold components of vector we are creating
     */
	Vector(std::vector<double> &init) : m_data(init) {};

    /**
     * @brief Constructor with iterators
     * @param beg - iterator to the first element of std::vector which hold components
     * @param end - iterator one-past the last element of std::vector which hold components
     */
	Vector(std::vector<double>::iterator beg, std::vector<double>::iterator end)
		: m_data(beg, end) {}

    /**
     * @brief Calculate the magnitute of the vector
     * @return magnitute of the vector
     */
	double len() const
	{
        // |v| = sqrt(c1^2 + c2^2 + c3^2 + ... + cn^2) where ci is i-th component
		double sum = 0.0;
        //calculate c1^2 + c2^2 + ... + cn^2
		for (unsigned i = 0; i < m_data.size(); i++)
            sum += (m_data[i] * m_data[i]);
        return sqrt(sum); //return magnitute
	}

    /**
     * @brief Acess component of vector
     * @param index - index of the component we wish to access
     * @return Reference bound to component of the vector indexed by [index]
     */
	double& operator[](unsigned index) { return m_data[index]; }

    /**
     * @brief Subtract 2 vectors
     * @param rhs - vector on the right side of operator -
     * @return Result of v1 - v2, where v1 is [this] vector and v2 is [rhs] vector
     */
	Vector operator-(const Vector &rhs)
	{
        std::vector<double> dat(m_data.size(), 0.0); //temp vector to hold subtracted components
		for (unsigned i = 0; i < m_data.size(); i++)
			dat[i] = m_data[i] - rhs.m_data[i];
		return Vector(dat);
	}

    /**
     * @brief Getter for m_data attribute
     * @return m_data
     */
	std::vector<double>& get_data() { return m_data; }
private:
    /**
     * @brief Vector of doubles which hold components (values of components)
     */
	std::vector<double> m_data;
};

#endif

