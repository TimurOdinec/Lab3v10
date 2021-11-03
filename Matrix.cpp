#include "Matrix.h"
#include <iostream>
#include <random>
#include <vector>

/// <summary>
/// конструктор
/// </summary>
Matrix::Matrix()
{
	Matrix::countRows = 0;
	Matrix::countColumns = 0;
	Matrix::pointerMatrix = NULL;
}
/// <summary>
/// конструктор с параметрами
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
/// конструктор копирования
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
/// деструктор
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
/// метод добавляет (наполняет) элементы в матрицу
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
/// метод вывода матрицы в консоль
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
/// метод для вычисления суммы двух матриц
/// </summary>
/// <param name="matrixA"></param>
/// <param name="matrixB"></param>
/// <returns></returns>
Matrix Matrix::summMatrix(Matrix matrixA, Matrix matrixB)
{
	//матрицы должны быть раномерными, складываем поэлементно, соответственно индексам
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
		std::cout << "Размерность матриц не совпадает" << std::endl;
	}
	//возвращаем указатель на матрицу - сумму
	return *this;
}
/// <summary>
/// метод для вычисления произведегния матрицы на скаляр
/// </summary>
/// <param name="scalar"></param>
/// <param name="matrixA"></param>
/// <returns></returns>
Matrix Matrix::productMatrixScalar(int scalar, Matrix matrixA)
{
	//std::cout << "productMatrixScalar" << std::endl;
	//умножаем каждый элемент матрицы на скаляр
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
/// метод для перестановки строк матрицы по заданному вектору транспозиции
/// </summary>
/// <param name="matrixA"></param>
/// <returns></returns>
Matrix Matrix::changeMatrixVector(Matrix matrixA)
{
	//определяем кол-во строк матрицы, чтобы знать кол-во чисел в векторе транспозиции
	int rowCount = matrixA.countRows;
	std::cout << "вектор транспозиции (рандомный):" << std::endl;
	std::vector<int> vectorTransposition;
	//наполняем вектор числами: 1,2,3,4,...,кол-во строк матрицы
	for (int i = 1; i <= rowCount; i++)
	{
		vectorTransposition.push_back(i);
	}
	//переставим случайным образом числа внутри вектора: 5,1,3,...
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
	//переставляем строки матрицы по ветору
	//если вектор (3,1,4,2)
	//то 3 строка матрицы становится на первое место
	//1 строка - второе место
	//4 строка - третье место
	//2 строка - четвертое место
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
