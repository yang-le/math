/*
 * fraction.hpp
 *
 *  Created on: 2014Äê9ÔÂ7ÈÕ
 *      Author: yangle
 */

#ifndef FRACTION_HPP_
#define FRACTION_HPP_

namespace math
{

template <typename T>
class fraction
{
	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const fraction<U>&);

	template <typename U>
	friend const fraction<U> operator*(const U&, const fraction<U>&);

public:
	fraction() {}
	fraction(const T& numerator, const T&denominator)
	:m_numerator(numerator), m_denominator(denominator) {}

private:
	T m_numerator;
	T m_denominator;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, const fraction<U>& frac)
{
	os << frac.m_numerator << "/" << frac.m_denominator;
	return os;
}

}



#endif /* FRACTION_HPP_ */
