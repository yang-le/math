/*
 * matrix.hpp
 *
 *  Created on:
 *      Author: yangle
 */

#ifndef MATRIX_HPP_
#define MATRIX_HPP_

#include <vector>
#include <ostream>
#include <algorithm>
#include <functional>
#include <numeric>

namespace math
{
template <typename T>
class vector;

template <typename T>
class matrix
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const matrix<U>&);

	template <typename U>
	friend const matrix<U> operator*(const U&, const matrix<U>&);

public:
	matrix() {}

	matrix(std::vector<vector<T>> vv)
	:m_vectors(vv) {}

public:
	matrix& operator+=(const matrix& rhs)
	{
		transform(begin(), end(), rhs.begin(), begin(), std::plus<vector<T>>());
		return *this;
	}

	matrix& operator-=(const matrix& rhs)
	{
		transform(begin(), end(), rhs.begin(), begin(), std::minus<vector<T>>());
		return *this;
	}

	matrix& operator*=(const T& rhs)
	{
		// i don't know how to imp it using transform, so
		for (auto &i : m_vectors)
			i *= rhs;

		return *this;
	}

	matrix& operator*=(const matrix& rhs)
	{
		std::vector<vector<T> > vv;
		vector<T> r;

		for (unsigned int i = 0; i < rows(); ++i) {
			for (unsigned int j = 0; j < rhs.cols(); ++j)
				r.push_back(row(i) * rhs.col(j));

			vv.push_back(r);
			r.clear();
		}

		m_vectors = vv;
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
	bool empty() const
	{
		return (0 == m_vectors.size());
	}

	unsigned int rows() const
	{
		return m_vectors.size();
	}

	unsigned int cols() const
	{
		return m_vectors[0].size();
	}

	vector<T>& row(unsigned int index)
	{
		return m_vectors[index];
	}

	const vector<T>& row(unsigned int index) const
	{
		return m_vectors[index];
	}

	const matrix row(unsigned int start, unsigned int end) const
	{
		std::vector<vector<T> > vv(end - start + 1);
		copy(begin() + start, begin() + end + 1, vv.begin());

		matrix result(vv);
		return result;
	}

	vector<T> col(unsigned int index)
	{
		vector<T> result;

		for (auto &row : m_vectors)
			result.push_back(row[index]);
		return result;
	}

	const vector<T> col(unsigned int index) const
	{
		vector<T> result;

		for (auto &row : m_vectors)
			result.push_back(row[index]);
		return result;
	}

	const matrix col(unsigned int start, unsigned int end) const
	{
		std::vector<vector<T> > vv;
		for (int i = start; i != end + 1; (start < end + 1) ? ++i : --i)
			vv.push_back(col(i));

		matrix result(vv);
		return result;
	}

	const matrix transpose() const
	{
		std::vector<vector<T> > vv;
		// this seems ugly
		for (unsigned int i = 0; i < cols(); ++i)
			vv.push_back(col(i));

		matrix result(vv);
		return result;
	}

public:
	typename std::vector<vector<T> >::const_iterator begin() const
	{
		return m_vectors.begin();
	}

	typename std::vector<vector<T> >::iterator begin()
	{
		return m_vectors.begin();
	}

	typename std::vector<vector<T> >::const_iterator end() const
	{
		return m_vectors.end();
	}

	typename std::vector<vector<T> >::iterator end()
	{
		return m_vectors.end();
	}

private:
	std::vector<vector<T> > m_vectors;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const matrix<U>& mat)
{
	if (mat.empty()) return os;

	typename std::vector<vector<U> >::const_iterator i;
	for (i = mat.begin(); i < mat.end() - 1; ++i)
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
