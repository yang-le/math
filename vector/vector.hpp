/*
 * vector.hpp
 *
 *  Created on: 2014��9��6��
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
class vector: public std::vector<T>
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const vector<U>&);

	template <typename U>
	friend const vector<U> operator*(const U&, const vector<U>&);

public:
	vector& operator+=(const vector& rhs)
	{
		std::plus<T> add;
		transform(this->begin(), this->end(), rhs.begin(), this->begin(), add);
		return *this;
	}

	vector& operator-=(const vector& rhs)
	{
		std::minus<T> sub;
		transform(this->begin(), this->end(), rhs.begin(), this->begin(), sub);
		return *this;
	}

	vector& operator*=(const T& rhs)
	{
		std::multiplies<T> mul;
		transform(this->begin(), this->end(), this->begin(), std::bind1st(mul, rhs));
		return *this;
	}

//	vector& operator/=(const vector& rhs);

	const vector operator+(const vector& rhs)
	{
		vector result = *this;
		result += rhs;
		return result;
	}

	const vector operator-(const vector& rhs)
	{
		vector result = *this;
		result -= rhs;
		return result;
	}

	const vector operator*(const T& rhs)
	{
		vector result = *this;
		result *= rhs;
		return result;
	}

	const T operator*(const vector& rhs)
	{
		return inner_product(this->begin(), this->end(), rhs.begin(), static_cast<T>(0));
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
