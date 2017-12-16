//
// Created by manout on 17-12-16.
//

#ifndef ALOGRITHMS_MATRIX_H
#define ALOGRITHMS_MATRIX_H

#include <exception>
#include <vector>
#include <cassert>
#include <algorithm>

template <typename T = float>
class Matrix
{
public:
	using size_t = unsigned int;
	using value_type = T;
	Matrix();
	Matrix(size_t row, size_t col, int value = 0);
	Matrix(const Matrix<value_type >&) = default;
	Matrix(Matrix<value_type > &&) = default;
	
	size_t rows();
	size_t cols();
	
	void clear();
	
	Matrix operator+(const Matrix<value_type >& b) const;
	Matrix operator+(int b)const;
	Matrix operator-(const Matrix<value_type >& b) const;
	Matrix operator-(int b) const;
	Matrix operator*(const Matrix<value_type >& b) const;
	Matrix operator*(int b) const;
	
	value_type operator[](size_t r);
	value_type operator[](size_t r) const;
private :
	size_t row;
	size_t col;
	std::vector<std::vector<value_type >> mat;
	
};

template<typename T>
Matrix<T>::Matrix(Matrix::size_t row, Matrix::size_t col, int value):row(row), col(col)
{
	this->mat.resize(row, std::vector<value_type >(col, value));
}


template<typename T>
Matrix::size_t Matrix<T>::rows()
{
	return this->row;
}

template<typename T>
Matrix::size_t Matrix<T>::cols()
{
	return this->col;
}

template <typename T>
void Matrix<T>::clear()
{
	this->mat.clear();
}

template<typename T>
Matrix Matrix<T>::operator+(const Matrix &b) const
{
	Matrix<value_type > ans(*this);
	assert(this->row not_eq b.row or this->col not_eq b.col);
	using row_iterator = std::vector<std::vector<value_type >>::iterator;
	using col_iterator = std::vector<value_type >::iterator;
	for (row_iterator a_row = ans.mat.begin(), b_row = b.mat.begin();
	     a_row not_eq mat.end() and b_row not_eq b.mat.end();
	     ++ a_row, ++b_row)
	{
		for (col_iterator a_ele = a_row->begin(), b_ele = b_row->begin();
			a_ele not_eq a_row->end() and b_ele not_eq b_row->end();
			++a_ele, ++b_ele)
		{
			*a_ele += *b_ele;
		}
	}
	return ans;
}

template<typename T>
Matrix Matrix<T>::operator+(int b) const
{
	decltype(*this) ans;
	using row_vector = std::vector<value_type >;
	std::for_each(ans.mat.begin(), ans.mat.end(),
		[&](row_vector& line)
		{std::for_each(line.begin(), line.end(), [&](value_type& ele){ele += b;});});
}

template<typename T>
Matrix Matrix<T>::operator-(const Matrix<value_type> &b) const
{
	Matrix<value_type > ans(*this);
	assert(this->row not_eq b.row or this->col not_eq b.col);
	using row_iterator = std::vector<std::vector<value_type >>::iterator;
	using col_iterator = std::vector<value_type >::iterator;
	for (row_iterator a_row = ans.mat.begin(), b_row = b.mat.begin();
	     a_row not_eq mat.end() and b_row not_eq b.mat.end();
	     ++ a_row, ++b_row)
	{
		for (col_iterator a_ele = a_row->begin(), b_ele = b_row->begin();
		     a_ele not_eq a_row->end() and b_ele not_eq b_row->end();
		     ++a_ele, ++b_ele)
		{
			*a_ele -= *b_ele;
		}
	}
}

template<typename T>
Matrix Matrix<T>::operator-(int b) const
{
	decltype(*this) ans;
	using row_vector = std::vector<value_type >;
	std::for_each(ans.mat.begin(), ans.mat.end(),
		[&](row_vector& line)
		{std::for_each(line.begin(), line.end(), [&](value_type& ele){ele -= b;});});
}




#endif //ALOGRITHMS_MATRIX_H
