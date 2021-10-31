#include "SquareMatrix.h"
#include <iostream>

SquareMatrix::SquareMatrix() : Matrix()
{

}
SquareMatrix::SquareMatrix(int sizeMatrix) : Matrix(sizeMatrix, sizeMatrix)
{

}
SquareMatrix::SquareMatrix(const SquareMatrix &objSquareMatrix)
{
	//std::cout << "constructor copy run" << std::endl;
	SquareMatrix::countRows = objSquareMatrix.countRows;
	SquareMatrix::countColumns = objSquareMatrix.countColumns;
	SquareMatrix::pointerMatrix = NULL;
	if (objSquareMatrix.pointerMatrix)
	{
		pointerMatrix = new int* [countRows];
		for (int count = 0; count < countRows; count++)
		{
			pointerMatrix[count] = new int[countColumns];
		}

		for (int i = 0; i < countRows; i++)
		{
			for (int j = 0; j < countColumns; j++)
			{
				pointerMatrix[i][j] = objSquareMatrix.pointerMatrix[i][j];
			}
		}
	}
}
SquareMatrix::~SquareMatrix()
{

}
SquareMatrix SquareMatrix::productMatrix(SquareMatrix sMatrixA, SquareMatrix sMatrixB)
{
	if (sMatrixA.countColumns == sMatrixB.countColumns
		&& sMatrixA.pointerMatrix && sMatrixB.pointerMatrix)
	{
		SquareMatrix::countColumns = sMatrixA.countColumns;
		SquareMatrix::countRows = sMatrixA.countRows;
		SquareMatrix::pointerMatrix = new int* [countRows];
		for (int count = 0; count < countRows; count++)
		{
			pointerMatrix[count] = new int[countColumns];
		}

		for (int i = 0; i < countRows; i++)
		{
			for (int j = 0; j < countColumns; j++)
			{
				int summ = 0;
				for (int k = 0; k < countColumns; k++)
				{
					summ += sMatrixA.pointerMatrix[i][k] * sMatrixB.pointerMatrix[k][j];
				}
				pointerMatrix[i][j] = summ;
			}
		}
	}
	else
	{
		std::cout << "Размерность матриц не совпадает" << std::endl;
	}
	return *this;
}
SquareMatrix SquareMatrix::transposeMatrix(SquareMatrix sMatrixA)
{
	SquareMatrix::countColumns = sMatrixA.countColumns;
	SquareMatrix::countRows = sMatrixA.countRows;
	SquareMatrix::pointerMatrix = new int* [countRows];
	for (int count = 0; count < countRows; count++)
	{
		pointerMatrix[count] = new int[countColumns];
	}
	for (int i = 0; i < countRows; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			pointerMatrix[j][i] = sMatrixA.pointerMatrix[i][j];
		}
	}
	return *this;
}
/*
*/
