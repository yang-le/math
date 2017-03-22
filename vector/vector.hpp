/*
 * vector.hpp
 *
 *  Created on:
 *      Author: yangle
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <vector>
#include <ostream>
#include <algorithm>
#include <functional>
#include <numeric>

namespace math
{
template <typename T>
class matrix;

template <typename T>
class vector: public std::vector<T>
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const vector<U>&);

	template <typename U>
	friend const vector<U> operator*(const U&, const vector<U>&);

public:
	// vector() {}

	// vector(unsigned int n, const T& value = T())
	// :std::vector<T>(n, value) {}

public:
	vector& operator+=(const vector& rhs)
	{
		transform(this->begin(), this->end(), rhs.begin(), this->begin(), std::plus<T>());
		return *this;
	}

	vector& operator-=(const vector& rhs)
	{
		transform(this->begin(), this->end(), rhs.begin(), this->begin(), std::minus<T>());
		return *this;
	}

	vector& operator*=(const T& rhs)
	{
		transform(this->begin(), this->end(), this->begin(), std::bind1st(std::multiplies<T>(), rhs));
		return *this;
	}

	vector& operator*=(const matrix<T>& rhs)
	{
		// not so good
		*this = *this * rhs;
		return *this;
	}

//	vector& operator/=(const vector& rhs);

	const vector operator+(const vector& rhs) const
	{
		vector result = *this;
		result += rhs;
		return result;
	}

	const vector operator-(const vector& rhs) const
	{
		vector result = *this;
		result -= rhs;
		return result;
	}

	const vector operator*(const T& rhs) const
	{
		vector result = *this;
		result *= rhs;
		return result;
	}

	const T operator*(const vector& rhs) const
	{
		return inner_product(this->begin(), this->end(), rhs.begin(), T());
	}

//	const vector operator*(const vector& rhs);
//	const vector operator/(const vector& rhs);

	const vector operator-() const
	{
		vector result = *this;
		result *= -1;
		return result;
	}
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const vector<U>& vec)
{
	if (vec.empty()) return os;

	typename vector<U>::const_iterator i;
	for (i = vec.begin(); i < vec.end() - 1; ++i)
		os << *i << " ";

	return os << *i;
}

template <typename U>
const vector<U> operator*(const U& lhs, const vector<U>& rhs)
{
	vector<U> result = rhs;
	result *= lhs;
	return result;
}

}

#endif /* VECTOR_HPP_ */
