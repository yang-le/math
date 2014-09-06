/*
 * main.cpp
 *
 *  Created on: 2014Äê9ÔÂ6ÈÕ
 *      Author: yangle
 */

#include <iostream>
#include "vector/vector.hpp"

using namespace std;

int main(int argc, char** argv)
{
	math::vector<int> vec;
	for (int i = 1; i < 10; ++i)
		vec.push_back(i);

	cout << -vec << endl;

	cout << vec + vec << endl;

	cout << vec - vec << endl;

	cout << 3 * vec << endl;

	cout << vec * -2 << endl;

	cout << vec * vec << endl;

	return 0;
}

