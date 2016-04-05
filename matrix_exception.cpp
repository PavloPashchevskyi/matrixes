#include "matrix_exception.h"

matrix_exception::matrix_exception(int iErrorCode) {
    _errorCode=iErrorCode;
    _error=new char[170];
    _wsError=new wchar_t[170];
    switch(_errorCode) {
        case MATRIX_UNSUBTRACTABLE_UNSUBLIMABLE: {
            strcpy(_error, "Exception: Matrixes are not suitable for subtraction and sublimation because of their different dimention!\n");
            wcscpy(_wsError, L"Exception: Matrixes are not suitable for subtraction and sublimation because of their different dimention!\n");
            break;
        }
        case MATRIX_UNMULTIPLIABLE_UNDIVISIBLE: {
         strcpy(_error, "Exception! Matrixes are not suitable for multiplication and division because columns quantity of the left matrix does not equal to the rows quantity of the right one!\n");
         wcscpy(_wsError, L"Exception! Matrixes are not suitable for multiplication and division because columns quantity of the left matrix does not equal to the rows quantity of the right one!\n");
         break;
        }
        case MATRIX_NON_SQUARE: {
            strcpy(_error, "Exception! Unable to calculate determinant of the matrix, because rows quantity does not equal to columns quantity!\n");
            wcscpy(_wsError, L"Exception! Unable to calculate delimiter of the matrix, because rows quantity does not equal to columns quantity!\n");
            break;
        }
        case MATRIX_NON_INVERSIBLE: {
            strcpy(_error, "Exception! Unable to calculate the inverse matrix! Determinant equals 0 or matrix is not square!\n");
            wcscpy(_wsError, L"Exception! Unable to calculate the inverse matrix! Determinant equals 0 or matrix is non-square!\n");
            break;
        }
        case MATRIX_DIVISOR_CONTENTS_ZERO: {
            strcpy(_error, "Exception! The right matrix contents one or more zero clauses! Unable to divide matrixes!\n");
            wcscpy(_wsError, L"Exception! The right matrix contents one or more zero clauses! Unable to divide matrixes!\n");
            break;
        }
        case MATRIX_DIVISION_MATRIX_BY_ZERO: {
            strcpy(_error, "Exception! The right number is zero! Unable to divide matrix by zero!\n");
            wcscpy(_wsError, L"Exception! The right number is zero! Unable to divide matrix by zero!\n");
            break;
        }
        case MATRIX_ROW_OUT_OF_MATRIX: {
            strcpy(_error, "Exception! Row number is less than 0 or more than (m-1), where m - rows quantity of the matrix!\n");
            wcscpy(_wsError, L"Exception! Row number is less than 0 or more than (m-1), where m - rows quantity of the matrix!\n");
            break;
        }
        case MATRIX_COLUMN_OUT_OF_MATRIX: {
            strcpy(_error, "Exception! Column number is less than 0 or more than (n-1), where n - columns quantity of the matrix!\n");
            wcscpy(_wsError, L"Exception! Column number is less than 0 or more than (n-1), where n - columns quantity of the matrix!\n");
            break;
        }
        case MATRIX_CLAUSE_OUT_OF_MATRIX: {
            strcpy(_error, "Exception! Row (column) number is out of range 0...m-1 (0...n-1), where m - rows quantity, n - columns quantity!\n");
            wcscpy(_wsError, L"Exception! Row (column) number is out of range 0...m-1 (0...n-1), where m - rows quantity, n - columns quantity!\n");
            break;
        }
        default: {
            strcpy(_error, "Exception! Unprocessed matrix exception!\n");
            wcscpy(_wsError, L"Exception! Unprocessed matrix exception!\n");
            break;
        }
    }
}

matrix_exception::matrix_exception(matrix_exception& me) {
    _errorCode=me._errorCode;
    strcpy(_error, me._error);
    wcscpy(_wsError, me._wsError);
}

int matrix_exception::errorCode() {
    return _errorCode;
}

char* matrix_exception::error() {
    return _error;
}

wchar_t* matrix_exception::errorW() {
    return _wsError;
}

matrix_exception::~matrix_exception() {
    delete [] _error;
    delete [] _wsError;
    _errorCode=0;
}
