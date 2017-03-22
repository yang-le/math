/*
 * main.cpp
 *
 *  Created on:
 *      Author: yangle
 */

#include <iostream>
#include "vector/vector.hpp"
#include "matrix/matrix.hpp"
#include "matrix/squareMatrix.hpp"
#include "fraction/fraction.hpp"

using namespace std;

int main(int argc, char** argv)
{
	math::fraction<int> frac(23, 43);
	cout << frac << endl;

	math::vector<int> vec;
	for (int i = 1; i < 4; ++i)
		vec.push_back(i);

	cout << -vec << endl;

	cout << vec + vec << endl;

	cout << vec - vec << endl;

	cout << 3 * vec << endl;

	cout << vec * -2 << endl;

	cout << vec * vec << endl;

	vector<math::vector<int> > vv(3, vec);
	math::squareMatrix<int> mat(vv);

	cout << -mat << endl << endl;

	cout << mat + mat << endl << endl;

	cout << mat - mat << endl << endl;

	cout << 3 * mat << endl << endl;

	cout << mat * -2 << endl << endl;

	cout << mat[1] << endl << endl;

	cout << mat.col(1, 2) << endl << endl;

	cout << mat.row(1, 2) << endl << endl;

	cout << mat.transpose() << endl << endl;

	cout << mat * mat << endl << endl;

	return 0;
}

