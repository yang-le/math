/*
 * matrix.hpp
 *
 *  Created on: 2014Äê9ÔÂ6ÈÕ
 *      Author: yangle
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

namespace math
{
template <typename T>
class matrix
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const matrix<U>&);

public:
	matrix();
	matrix(const matrix& rhs)
	{
		*this = rhs;
	}

	matrix(std::vector<vector<T> > vv)
	{
		m_vectors = vv;
	}

private:
	std::vector<vector<T> > m_vectors;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const matrix<U>& mat)
{
	typename std::vector<vector<U> >::const_iterator i;
	for (i = mat.m_vectors.begin(); i < mat.m_vectors.end() - 1; ++i)
		os << *i << std::endl;
	return os << *i;
}

}



#endif /* MATRIX_HPP_ */
