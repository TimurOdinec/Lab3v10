#pragma once
#include "Matrix.h"

class SquareMatrix : public Matrix
{
public:
	SquareMatrix();
	SquareMatrix(int);
	SquareMatrix(const SquareMatrix&);
	~SquareMatrix();

	SquareMatrix productMatrix(SquareMatrix, SquareMatrix);
	SquareMatrix transposeMatrix(SquareMatrix);
};