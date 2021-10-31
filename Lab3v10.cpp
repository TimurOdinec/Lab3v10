// Lab3v10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// ссылки:
// наследование
// https://ravesli.com/urok-154-bazovoe-nasledovanie-v-c/
// умножение матриц
// https://www.berdov.com/works/matrix/umnozhenie-matric/
// 
// 
// ЗАДАНИЕ
// 10.	Определить базовый класс для работы с матрицами, 
// предусмотрев ввод, вывод матриц и выполнение следующих операций: 
// а) сложение матриц; (равная размерность)
// б) умножение матрицы на скаляр;
// в) перестановка строк матрицы по заданному вектору транспозиции.
//          (вектор указывает порядок строк новой матрицы относительно старой)
// В производном классе реализовать указанные операции для квадратных матриц,
//  добавив выполнение следующих операций :
// а) транспонирование матрицы;
// б) умножение матриц. 
// 
// 
// исходная матрица A имела размер m×n, то транспонированная матрица AT будет размером n×m.
// Матрица-строка в результате транспонирования преобразуется в матрицу-столбец и наоборот. 
// Несложно увидеть, что ATij=Aji.
// Таким образом, для получения транспонированной матрицы достаточно 
// каждую строку исходной матрицы записать в виде столбца результирующей, 
// соблюдая порядок следования элементов.
//

#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Lab3v10 \n";
    
    int countRows;
    int countColumns;
    
    std::cout << "Введите кол-во строк матрицы:";
    std::cin >> countRows;
    std::cout << "Введите кол-во колонок матрицы:";
    std::cin >> countColumns;
    Matrix matrixA(countRows, countColumns);
    matrixA.addElements();
    matrixA.viewMatrix();

    std::cout << "Введите кол-во строк матрицы:";
    std::cin >> countRows;
    std::cout << "Введите кол-во колонок матрицы:";
    std::cin >> countColumns;
    Matrix matrixB(countRows, countColumns);
    matrixB.addElements();
    matrixB.viewMatrix();

    std::cout << "Сумма матриц (A+B):" << std::endl;
    Matrix matrixC;
    matrixC.summMatrix(matrixA, matrixB);
    matrixC.viewMatrix();
    
    std::cout << "Умножение матрицы на скаляр (5*A):" << std::endl;
    int scalar = 5;
    Matrix matrixD;
    matrixD.productMatrixScalar(scalar, matrixA);
    matrixD.viewMatrix();
    
    std::cout << "Введите кол-во строк матрицы:";
    std::cin >> countRows;
    std::cout << "Введите кол-во колонок матрицы:";
    std::cin >> countColumns;
    Matrix matrixE(countRows, countColumns);
    matrixE.addElements();
    matrixE.viewMatrix();

    std::cout << "Перестановка строк матрицы E по заданному вектору транспозиции:" << std::endl;
    Matrix matrixF;
    matrixF.changeMatrixVector(matrixE);
    matrixF.viewMatrix();
    
    std::cout << "###################################################" << std::endl;
    
    int countRowColumn;
    std::cout << "Введите кол-во строк-столбцов квадратной матрицы A:";
    std::cin >> countRowColumn;
    SquareMatrix sMatrixA(countRowColumn);
    sMatrixA.addElements();
    sMatrixA.viewMatrix();

    std::cout << "Введите кол-во строк-столбцов квадратной матрицы B:";
    std::cin >> countRowColumn;
    SquareMatrix sMatrixB(countRowColumn);
    sMatrixB.addElements();
    sMatrixB.viewMatrix();

    std::cout << "Произведение матриц (C=A*B):" << std::endl;
    SquareMatrix sMatrixC;
    sMatrixC.productMatrix(sMatrixA, sMatrixB);
    sMatrixC.viewMatrix();

    std::cout << "Сложение матриц (C=A+B):" << std::endl;
    SquareMatrix sMatrixF;
    sMatrixF.summMatrix(sMatrixA, sMatrixB);
    sMatrixF.viewMatrix();

    std::cout << "Умножение матрицы на скалар (3*A):" << std::endl;
    int scalarSecond = 3;
    SquareMatrix sMatrixG;
    sMatrixG.productMatrixScalar(scalarSecond, sMatrixA);
    sMatrixG.viewMatrix();

    std::cout << "Введите кол-во строк-столбцов квадратной матрицы D:";
    std::cin >> countRowColumn;
    SquareMatrix sMatrixD(countRowColumn);
    sMatrixD.addElements();
    std::cout << "Транспонирование матрицы D:" << std::endl;
    SquareMatrix sMatrixE;
    sMatrixE.transposeMatrix(sMatrixD);
    sMatrixD.viewMatrix();
    std::cout << std::endl;
    sMatrixE.viewMatrix();
    
    return 0;
}

