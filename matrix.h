/* 
 * File:   matrix.h
 * Author: ppd
 *
 * Created on 27 марта 2015 г., 15:43
 */

#ifndef MATRIX_H
#define	MATRIX_H

#include "matrix_exception.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

class matrix {
    unsigned rowsq;
    unsigned columnsq;
    double **clauses;
    static double accuracy;
public:
    matrix();//creates an empty matrix with dimention 1x1
    matrix(unsigned uRowsQ, unsigned uColumnsQ);//creates an empty matrix with dimention uRowsQ x uColumnsQ
    matrix(matrix &right);//copy right matrix to the left
    matrix& operator=(matrix &right);//assign right matrix to the left
    matrix empty();//returns matrix with clauses =0
    matrix identity();//returns matrix with main diagonal elements =1
    unsigned operator==(matrix &right);//checks if left and right matrixes are equal
    unsigned operator!=(matrix &right);//checks if left and right matrixes are non-equal
    unsigned operator<(matrix &right);//checks if left matrix is less than right
    unsigned operator<=(matrix &right);//checks if left matrix is no more than right
    unsigned operator>(matrix &right);//checks if left matrix is greater than right
    unsigned operator>=(matrix &right);//checks if left matrix is no less than right
    static double getAccuracy();//returns difference between the divisor and zero
    static void setAccuracy(double dAccuracy=0.000001);//sets difference which must be between the divisor and zero
    unsigned approximateEquality(matrix &right);//checks if left is differ from right less than on a given accuracy  
    matrix operator+(matrix &right);//sublimates left and right matrixes
    matrix operator-(matrix &right);//subtracts left and right matrixes
    matrix operator*(double right);//multiplicates left matrix by right number
    friend matrix operator*(double left, matrix &right);//multiplicates left number by right matrix
    matrix operator*(matrix &right);//multiplicates left and right matrixes
    matrix powm(int y);//returns matrix in the power of y
    matrix operator/(double right);//divides left matrix by right number
    friend matrix operator/(double left, matrix &right);//divides left number by right matrix
    matrix operator/(matrix &right);// divides left and right matrixes
    unsigned getRowsQuantity();//returns rows quantity
    unsigned getColumnsQuantity();//returns columns quantity
    double** getMatrixAsArrayOfRows();//returns double pointer to the matrix
    double* getMatrix();//returns pointer to the matrix
    void setMatrix(double *dMatrix);//copies clauses of dMatrix to the matrix
    void setArrayOfRows(double **dMatrix);//copies clauses of dMatrix to the matrix
    double* getRow(unsigned rn);//returns row number cn (starting with 0)
    void setRow(unsigned rn, double *row);// copies row vector to the matrix row number rn (starting with 0)
    double* getColumn(unsigned cn);//returns column number cn (starting with 0)
    void setColumn(unsigned cn, double *column);//copies column vector to the matrix column number cn (starting with 0)
    double getClause(unsigned rn, unsigned cn);//returns clause of matrix, which situated in row number rn and column number cn (starting with 0)
    void setClause(unsigned rn, unsigned cn, double clause);//copies clause to the row number rn and column number cn (starting with 0)
    void replaceRows(unsigned rn1, unsigned rn2);//swaps rows rn1 and rn2 (starting with 0)
    void replaceColumns(unsigned cn1, unsigned cn2);//swaps columns cn1 and cn2 (starting with 0)
    void multiplicateRowByNumber(unsigned rn, double number);//multiplicates row number rn (starting with 0) by number
    void multiplicateColumnByNumber(unsigned cn, double number);//multiplicates column number cn (starting with 0) by number
    void addOneRowToAnotherMultiplicated(unsigned rn1, unsigned rn2, double number);//add row number rn1 to row number rn2 multiplicated by number
    void addOneColumnToAnotherMultiplicated(unsigned cn1, unsigned cn2, double number);//add column number cn1 to column number cn2 multiplicated by number
    matrix deleteRowColumn(unsigned rn, unsigned cn);//deletes row rn and column cn . Rows and columns numeration starting with 0
    matrix transpose();//transposes original matrix and returns transposed matrix
    double det();//determinant
    double minor(unsigned rn, unsigned cn);//returns determinant of matrix in which row number rn (starting with 0) and column number cn (starting with 0) were deleted
    double cofactor(unsigned rn, unsigned cn);//returns minor of clause in row number rn (starting with 0) and column number cn (starting with 0) multiplicated by -1 in power (order+order+2)
    matrix adjoint();//returns adjoint matrix
    matrix  inverse();//returns matrix inverted
    matrix absm();//returns module of matrix
    double m_norm();//returns the largest sum of row clauses
    double l_norm();////returns the largest sum of column clauses
    double k_norm();//returns square root from sum of the clauses squares
    char* outputMatrix(const char greeting[60]);//returns char* string with greeting message (59 characters maximum) and clauses of matrixes
    wchar_t* outputMatrix(const wchar_t greeting[60]);//returns wchar_t* string with greating message (59 symbols maximum) and clauses of matrixes
    char* outputMatrixRow(unsigned rn, const char greeting[60]);//returns char* string with greating message (59 symbols maximum) and clauses of row number rn
    wchar_t* outputMatrixRow(unsigned rn, const wchar_t greeting[60]);//returns wchar_t* string with greating message (59 symbols maximum) and clauses of row number rn
    char* outputMatrixColumn(unsigned cn, const char greeting[60]);//returns char* string with greeting message (59 symbols maximum) and clauses of column number cn
    wchar_t* outputMatrixColumn(unsigned cn, const wchar_t greeting[60]);//returns char* string with greeting message (59 symbols maximum) and clauses of column number cn
    ~matrix();//delete matrix from the memory
};

#endif	/* MATRIX_H */

