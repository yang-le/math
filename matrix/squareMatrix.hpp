/*
 * squareMatrix.hpp
 *
 *  Created on:
 *      Author: yangle
 */

#ifndef SQUAREMATRIX_HPP_
#define SQUAREMATRIX_HPP_

namespace math
{
template <typename T>
class matrix;

template <typename T>
class squareMatrix: public matrix<T>
{
public:
	squareMatrix() {}

	squareMatrix(std::vector<vector<T> > vv)
	:matrix<T>(vv) {}

public:
	const T det() const;
	const squareMatrix inverse() const;

public:
	squareMatrix& operator/=(const squareMatrix&);
	const squareMatrix operator/(const squareMatrix&) const;
};
}

#endif /* SQUAREMATRIX_HPP_ */
