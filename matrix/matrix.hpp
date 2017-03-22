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
class matrix : public std::vector<vector<T>>
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const matrix<U>&);

	template <typename U>
	friend const matrix<U> operator*(const U&, const matrix<U>&);

public:
	matrix& operator+=(const matrix& rhs)
	{
		transform(std::begin(*this), std::end(*this), std::begin(rhs), std::begin(*this), std::plus<vector<T>>());
		return *this;
	}

	matrix& operator-=(const matrix& rhs)
	{
		transform(std::begin(*this), std::end(*this), std::begin(rhs), std::begin(*this), std::minus<vector<T>>());
		return *this;
	}

	matrix& operator*=(const T& rhs)
	{
		// i don't know how to imp it using transform, so
		for (auto &i : *this)
			i *= rhs;

		return *this;
	}

	matrix& operator*=(const matrix& rhs)
	{
		vector<T> r;

		for (unsigned int i = 0; i < rows(); ++i) {
			for (unsigned int j = 0; j < rhs.cols(); ++j)
				r.push_back(row(i) * rhs.col(j));

			push_back(r);
			r.clear();
		}

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

public:
	unsigned int rows() const
	{
		return this->size();
	}

	unsigned int cols() const
	{
		return (*this)[0].size();
	}

	vector<T>& row(unsigned int index)
	{
		return (*this)[index];
	}

	const vector<T>& row(unsigned int index) const
	{
		return (*this)[index];
	}

	const matrix row(unsigned int start, unsigned int end) const
	{
		matrix result;
		result.resize(end - start + 1);

		copy(begin(*this) + start, begin(*this) + end + 1, begin(result));
		
		return result;
	}

	vector<T> col(unsigned int index)
	{
		vector<T> result;

		for (auto &row : *this)
			result.push_back(row[index]);
		return result;
	}

	const vector<T> col(unsigned int index) const
	{
		vector<T> result;

		for (auto &row : *this)
			result.push_back(row[index]);
		return result;
	}

	const matrix col(unsigned int start, unsigned int end) const
	{
		matrix result;
		for (int i = start; i != end + 1; (start < end + 1) ? ++i : --i)
			result.push_back(col(i));

		return result.transpose();
	}

	const matrix transpose() const
	{
		matrix result;
		// this seems ugly
		for (unsigned int i = 0; i < cols(); ++i)
			result.push_back(col(i));

		return result;
	}
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
