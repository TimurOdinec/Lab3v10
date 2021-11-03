#pragma once

/// <summary>
/// класс-родитель объектов матриц
/// </summary>
class Matrix
{
public:
	int countRows;			//кол-во строк
	int countColumns;		//кол-во колонок
	int** pointerMatrix;	//указатель на массив указателей

	Matrix();				//конструктор
	Matrix(int, int);		//конструктор с параметрами
	Matrix(const Matrix &);	//конструктор копирования
	~Matrix();				//деструктор

	void addElements();		//метод добавления элементов
	void viewMatrix();		//метод вывода в консоль матрицы

	Matrix summMatrix(Matrix, Matrix);			//метод нахождения суммы матриц
	Matrix productMatrixScalar(int, Matrix);	//метод произведения матрицы на скаляр
	Matrix changeMatrixVector(Matrix);			//метор перестановки строк по вектору транспозиции
};