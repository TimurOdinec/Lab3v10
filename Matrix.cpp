#include "Matrix.h"
#include <iostream>
#include <random>
#include <vector>

/// <summary>
/// �����������
/// </summary>
Matrix::Matrix()
{
	Matrix::countRows = 0;
	Matrix::countColumns = 0;
	Matrix::pointerMatrix = NULL;
}
/// <summary>
/// ����������� � �����������
/// </summary>
/// <param name="countRows"></param>
/// <param name="countColumns"></param>
Matrix::Matrix(int countRows, int countColumns)
{
	Matrix::countRows = countRows;
	Matrix::countColumns = countColumns;
	Matrix::pointerMatrix = new int* [countRows];
	for (int count = 0; count < countRows; count++)
	{
		pointerMatrix[count] = new int[countColumns];
	}
}
/// <summary>
/// ����������� �����������
/// </summary>
/// <param name="objMatrix"></param>
Matrix::Matrix(const Matrix &objMatrix)
{
	//std::cout << "constructor copy run" << std::endl;
	Matrix::countRows = objMatrix.countRows;
	Matrix::countColumns = objMatrix.countColumns;
	Matrix::pointerMatrix = NULL;
	if (objMatrix.pointerMatrix)
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
				pointerMatrix[i][j] = objMatrix.pointerMatrix[i][j];
			}
		}
	}
}
/// <summary>
/// ����������
/// </summary>
Matrix::~Matrix()
{
	if (pointerMatrix)
	{
		for (int i = 0; i < countRows; i++) delete[]pointerMatrix[i];
	}
	delete[]pointerMatrix;
}
/// <summary>
/// ����� ��������� (���������) �������� � �������
/// </summary>
void Matrix::addElements()
{
	for (int i = 0; i < Matrix::countRows; i++)
	{
		for (int j = 0; j < Matrix::countColumns; j++)
		{
			std::cout << "elem[" << i << "," << j << "]=";
			std::cin >> Matrix::pointerMatrix[i][j];
		}
	}
}
/// <summary>
/// ����� ������ ������� � �������
/// </summary>
void Matrix::viewMatrix()
{
	for (int i = 0; i < countRows; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			std::cout << pointerMatrix[i][j] << "; ";
		}
		std::cout << std::endl;
	}
}
/// <summary>
/// ����� ��� ���������� ����� ���� ������
/// </summary>
/// <param name="matrixA"></param>
/// <param name="matrixB"></param>
/// <returns></returns>
Matrix Matrix::summMatrix(Matrix matrixA, Matrix matrixB)
{
	//������� ������ ���� �����������, ���������� �����������, �������������� ��������
	if (matrixA.countColumns == matrixB.countColumns 
		&& matrixA.countRows == matrixB.countRows
		&& matrixA.pointerMatrix && matrixB.pointerMatrix)
	{
		Matrix::countColumns = matrixA.countColumns;
		Matrix::countRows = matrixA.countRows;
		Matrix::pointerMatrix = new int* [countRows];
		for (int count = 0; count < countRows; count++)
		{
			pointerMatrix[count] = new int[countColumns];
		}

		for (int i = 0; i < countRows; i++)
		{
			for (int j = 0; j < countColumns; j++)
			{
				pointerMatrix[i][j] = matrixA.pointerMatrix[i][j] + matrixB.pointerMatrix[i][j];
			}
		}
	}
	else
	{
		std::cout << "����������� ������ �� ���������" << std::endl;
	}
	//���������� ��������� �� ������� - �����
	return *this;
}
/// <summary>
/// ����� ��� ���������� ������������� ������� �� ������
/// </summary>
/// <param name="scalar"></param>
/// <param name="matrixA"></param>
/// <returns></returns>
Matrix Matrix::productMatrixScalar(int scalar, Matrix matrixA)
{
	//std::cout << "productMatrixScalar" << std::endl;
	//�������� ������ ������� ������� �� ������
	Matrix::countColumns = matrixA.countColumns;
	Matrix::countRows = matrixA.countRows;
	Matrix::pointerMatrix = new int* [countRows];
	for (int count = 0; count < countRows; count++)
	{
		pointerMatrix[count] = new int[countColumns];
	}

	for (int i = 0; i < countRows; i++)
	{
		for (int j = 0; j < countColumns; j++)
		{
			pointerMatrix[i][j] = scalar * matrixA.pointerMatrix[i][j];
		}
	}
	return *this;
}
/// <summary>
/// ����� ��� ������������ ����� ������� �� ��������� ������� ������������
/// </summary>
/// <param name="matrixA"></param>
/// <returns></returns>
Matrix Matrix::changeMatrixVector(Matrix matrixA)
{
	//���������� ���-�� ����� �������, ����� ����� ���-�� ����� � ������� ������������
	int rowCount = matrixA.countRows;
	std::cout << "������ ������������ (���������):" << std::endl;
	std::vector<int> vectorTransposition;
	//��������� ������ �������: 1,2,3,4,...,���-�� ����� �������
	for (int i = 1; i <= rowCount; i++)
	{
		vectorTransposition.push_back(i);
	}
	//���������� ��������� ������� ����� ������ �������: 5,1,3,...
	std::random_device randomDevice;
	std::mt19937 g(randomDevice());
	std::shuffle(vectorTransposition.begin(), vectorTransposition.end(), g);
	std::copy(vectorTransposition.begin(), vectorTransposition.end(), 
				std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
	
	Matrix::countColumns = matrixA.countColumns;
	Matrix::countRows = matrixA.countRows;
	Matrix::pointerMatrix = new int* [countRows];
	for (int count = 0; count < countRows; count++)
	{
		pointerMatrix[count] = new int[countColumns];
	}
	//������������ ������ ������� �� ������
	//���� ������ (3,1,4,2)
	//�� 3 ������ ������� ���������� �� ������ �����
	//1 ������ - ������ �����
	//4 ������ - ������ �����
	//2 ������ - ��������� �����
	for (int i = 0; i < countRows; i++)
	{
		int step = 0;
		for (int indexNew : vectorTransposition)
		{
			if (i == step) 
			{
				//std::cout << "indexNew:" << indexNew << "step:" << step << "i:" << i << std::endl;
				for (int j = 0; j < countColumns; j++)
				{
					pointerMatrix[i][j] = matrixA.pointerMatrix[indexNew - 1][j];
				}
			}
			step++;
		}
	}
	return *this;
}
