/*
 * matrix.hpp
 *
 *  Created on: 2014Äê9ÔÂ6ÈÕ
 *      Author: yangle
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>
#include <ostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include "../vector/vector.hpp"

namespace math
{
template <typename T>
class matrix
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const matrix<U>&);

	template <typename U>
	friend const matrix<U> operator*(const U&, const matrix<U>&);

public:
	matrix()
	{

	}

	matrix(const matrix& rhs)
	{
		*this = rhs;
	}

	matrix(std::vector<vector<T> > vv)
	{
		m_vectors = vv;
	}

public:
	matrix& operator+=(const matrix& rhs)
	{
		transform(m_vectors.begin(), m_vectors.end(), rhs.m_vectors.begin(), m_vectors.begin(), std::plus<vector<T> >());
		return *this;
	}

	matrix& operator-=(const matrix& rhs)
	{
		transform(m_vectors.begin(), m_vectors.end(), rhs.m_vectors.begin(), m_vectors.begin(), std::minus<vector<T> >());
		return *this;
	}

	matrix& operator*=(const T& rhs)
	{
		// i don't know how to imp it using transform, so
		for (typename std::vector<vector<T> >::iterator i = m_vectors.begin(); i < m_vectors.end(); ++i)
			(*i) *= rhs;

		return *this;
	}

	matrix& operator*=(const matrix& rhs)
	{
		std::vector<vector<T> > vv;
		vector<T> row;
		// use ugly for for
		return *this;
	}

	const matrix operator+(const matrix& rhs) const
	{
		matrix result = *this;
		result += rhs;
		return result;
	}

	const matrix operator-(const matrix& rhs) const
	{
		matrix result = *this;
		result -= rhs;
		return result;
	}

	const matrix operator*(const T& rhs) const
	{
		matrix result = *this;
		result *= rhs;
		return result;
	}

	const matrix operator*(const matrix& rhs) const
	{
		matrix result = *this;
		result *= rhs;
		return result;
	}

	const matrix operator-() const
	{
		matrix result = *this;
		result *= -1;
		return result;
	}

	vector<T>& operator[](unsigned int index)
	{
		return m_vectors[index];
	}

	const vector<T>& operator[](unsigned int index) const
	{
		return m_vectors[index];
	}

public:
	vector<T>& row(unsigned int index)
	{
		return m_vectors[index];
	}

	const vector<T>& row(unsigned int index) const
	{
		return m_vectors[index];
	}

	vector<T> col(unsigned int index)
	{
		vector<T> result;
		// this seems ugly
		for (typename std::vector<vector<T> >::iterator i = m_vectors.begin(); i < m_vectors.end(); ++i)
			result.push_back((*i)[index]);
		return result;
	}

	const vector<T> col(unsigned int index) const
	{
		vector<T> result;
		// this seems ugly
		for (typename std::vector<vector<T> >::iterator i = m_vectors.begin(); i < m_vectors.end(); ++i)
			result.push_back((*i)[index]);
		return result;
	}

	matrix& transpose()
	{
		std::vector<vector<T> > vv;
		// this seems ugly
		for (unsigned int i = 0; i < m_vectors[0].size(); ++i)
			vv.push_back(col(i));

		m_vectors = vv;
		return *this;
	}

	const matrix transpose() const
	{
		matrix result = *this;
		result.transpose();
		return result;
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

template <typename U>
const matrix<U> operator*(const U& lhs, const matrix<U>& rhs)
{
	matrix<U> result = rhs;
	result *= lhs;
	return result;
}

}

#endif /* MATRIX_HPP_ */
