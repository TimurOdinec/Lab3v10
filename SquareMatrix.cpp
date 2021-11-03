#include "SquareMatrix.h"
#include <iostream>

/// <summary>
/// �����������
/// </summary>
SquareMatrix::SquareMatrix() : Matrix()
{

}
/// <summary>
/// ����������� � ����������
/// </summary>
/// <param name="sizeMatrix"></param>
SquareMatrix::SquareMatrix(int sizeMatrix) : Matrix(sizeMatrix, sizeMatrix)
{

}
/// <summary>
/// ����������� �����������
/// </summary>
/// <param name="objSquareMatrix"></param>
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
/// <summary>
/// ����������
/// </summary>
SquareMatrix::~SquareMatrix()
{

}
/// <summary>
/// ����� ��� ���������� ������������ ������
/// </summary>
/// <param name="sMatrixA"></param>
/// <param name="sMatrixB"></param>
/// <returns></returns>
SquareMatrix SquareMatrix::productMatrix(SquareMatrix sMatrixA, SquareMatrix sMatrixB)
{
	//������� ������ ���� ������������
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
		//����������� ������� �� ������� (������ ������� �������-������������ ����� 
		//����� ������������ ��������������� ��������� ���� ������)
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
		std::cout << "����������� ������ �� ���������" << std::endl;
	}
	return *this;
}
/// <summary>
/// ����� ���������������� ������� (�������� �������� ������������ ������� ���������)
/// 1 2 3		1 4 7
/// 4 5 6  =>	2 5 8
/// 7 8 9		3 6 9
/// </summary>
/// <param name="sMatrixA"></param>
/// <returns></returns>
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

