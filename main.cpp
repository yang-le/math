/*
 * main.cpp
 *
 *  Created on:
 *      Author: yangle
 */

#include <gtest/gtest.h>
#include "vector/vector.hpp"
#include "matrix/matrix.hpp"
#include "matrix/squareMatrix.hpp"
#include "fraction/fraction.hpp"

class VectorTest : public testing::Test
{
protected:
	static const size_t SIZE = 4;

    virtual void SetUp()
    {
		for (int i = 0; i < SIZE; ++i) {
			m_vec.push_back(i);
		}
    }

    virtual void TearDown()
    {
        m_res.clear();
    }

    math::vector<int> m_vec;
	math::vector<int> m_res;	
};

TEST_F(VectorTest, minus)
{	
	for (auto &e : m_vec) {
		m_res.push_back(-e);
	}

    EXPECT_EQ(-m_vec, m_res);
}

TEST_F(VectorTest, add)
{
	for (auto &e : m_vec) {
		m_res.push_back(e + e);
	}

    EXPECT_EQ(m_vec + m_vec, m_res);
}

TEST_F(VectorTest, sub)
{
	for (auto &e : m_vec) {
		m_res.push_back(e - e);
	}

    EXPECT_EQ(m_vec - m_vec, m_res);
}

TEST_F(VectorTest, number_mul)
{
	for (auto &e : m_vec) {
		m_res.push_back(3 * e);
	}

    EXPECT_EQ(3 * m_vec, m_res);
}

TEST_F(VectorTest, mul_number)
{
	for (auto &e : m_vec) {
		m_res.push_back(-2 * e);
	}

    EXPECT_EQ(m_vec * -2, m_res);
}

TEST_F(VectorTest, mul)
{
	int result = 0;
	for (int i = 1; i < SIZE; ++i)
		result += i * i;

    EXPECT_EQ(m_vec * m_vec, result);
}

class MatrixTest : public testing::Test
{
protected:
	static const size_t SIZE = 4;	

    virtual void SetUp()
    {
		math::vector<int> vec;
		for (int i = 0; i < SIZE; ++i) {
			vec.clear();
			for (int j = 0; j < SIZE; ++j) {
				vec.push_back(i);
			}
			m_mat.push_back(vec);
		}
    }

    virtual void TearDown()
    {
        m_res.clear();
    }

    math::squareMatrix<int> m_mat;
	math::squareMatrix<int> m_res;		
};


TEST_F(MatrixTest, minus)
{	
	for (auto &e : m_mat) {
		m_res.push_back(-e);
	}

    EXPECT_EQ(-m_mat, m_res);
}

TEST_F(MatrixTest, add)
{	
	for (auto &e : m_mat) {
		m_res.push_back(e + e);
	}

    EXPECT_EQ(m_mat + m_mat, m_res);
}

TEST_F(MatrixTest, sub)
{	
	for (auto &e : m_mat) {
		m_res.push_back(e - e);
	}

    EXPECT_EQ(m_mat - m_mat, m_res);
}

TEST_F(MatrixTest, number_mul)
{	
	for (auto &e : m_mat) {
		m_res.push_back(3 * e);
	}

    EXPECT_EQ(3 * m_mat, m_res);
}

TEST_F(MatrixTest, mul_number)
{	
	for (auto &e : m_mat) {
		m_res.push_back(-2 * e);
	}

    EXPECT_EQ(m_mat * -2, m_res);
}

TEST_F(MatrixTest, col)
{	
    EXPECT_EQ(m_mat.col(0, m_mat.cols() - 1), m_mat);
}

TEST_F(MatrixTest, row)
{	
    EXPECT_EQ(m_mat.row(0, m_mat.rows() - 1), m_mat);
}

TEST_F(MatrixTest, transpose)
{	
    EXPECT_EQ(m_mat.transpose().transpose(), m_mat);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
