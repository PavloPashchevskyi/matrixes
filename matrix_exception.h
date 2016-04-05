/* 
 * File:   matrix_exception.h
 * Author: ppd
 *
 * Created on 18 жовтня 2015, 22:51
 */

#ifndef MATRIX_EXCEPTION_H
#define	MATRIX_EXCEPTION_H

#include <string.h>

enum EMatrixExceptions {
    MATRIX_UNSUBTRACTABLE_UNSUBLIMABLE=101,
    MATRIX_UNMULTIPLIABLE_UNDIVISIBLE=102,
    MATRIX_NON_SQUARE=103,
    MATRIX_NON_INVERSIBLE=104,
    MATRIX_DIVISOR_CONTENTS_ZERO=106,
    MATRIX_DIVISION_MATRIX_BY_ZERO=206,
    MATRIX_ROW_OUT_OF_MATRIX=301,
    MATRIX_COLUMN_OUT_OF_MATRIX=302,
    MATRIX_CLAUSE_OUT_OF_MATRIX=303
};

class matrix_exception {
    int _errorCode;
    char *_error;
    wchar_t *_wsError;
public:
    matrix_exception(int iErrorCode);
    matrix_exception(matrix_exception &me);
    int errorCode();
    char* error();
    wchar_t* errorW();
    ~matrix_exception();
};

#endif	/* MATRIX_EXCEPTION_H */

