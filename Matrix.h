#pragma once

/// <summary>
/// �����-�������� �������� ������
/// </summary>
class Matrix
{
public:
	int countRows;			//���-�� �����
	int countColumns;		//���-�� �������
	int** pointerMatrix;	//��������� �� ������ ����������

	Matrix();				//�����������
	Matrix(int, int);		//����������� � �����������
	Matrix(const Matrix &);	//����������� �����������
	~Matrix();				//����������

	void addElements();		//����� ���������� ���������
	void viewMatrix();		//����� ������ � ������� �������

	Matrix summMatrix(Matrix, Matrix);			//����� ���������� ����� ������
	Matrix productMatrixScalar(int, Matrix);	//����� ������������ ������� �� ������
	Matrix changeMatrixVector(Matrix);			//����� ������������ ����� �� ������� ������������
};