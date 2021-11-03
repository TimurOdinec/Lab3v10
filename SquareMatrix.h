#pragma once
#include "Matrix.h"

/// <summary>
/// �����-����������� �� ������ Matrix - ���������� �������
/// </summary>
class SquareMatrix : public Matrix
{
public:
	SquareMatrix();						//�����������
	SquareMatrix(int);					//����������� � ����������
	SquareMatrix(const SquareMatrix&);	//����������� �����������
	~SquareMatrix();					//����������

	SquareMatrix productMatrix(SquareMatrix, SquareMatrix);	//����� �������� ������������ ������
	SquareMatrix transposeMatrix(SquareMatrix);				//����� ���������������� �������
};