#pragma once
#include "Matrix.h"

/// <summary>
/// калсс-производный от класса Matrix - квадратная матрица
/// </summary>
class SquareMatrix : public Matrix
{
public:
	SquareMatrix();						//конструктор
	SquareMatrix(int);					//конструктор с параметром
	SquareMatrix(const SquareMatrix&);	//конструктор копирования
	~SquareMatrix();					//деструктор

	SquareMatrix productMatrix(SquareMatrix, SquareMatrix);	//метод подсчета произведения матриц
	SquareMatrix transposeMatrix(SquareMatrix);				//метод транспонирования матрицы
};