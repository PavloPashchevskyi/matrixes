#include "matrix.h"

double matrix::accuracy;

matrix::matrix() {
    rowsq=1;
    columnsq=1;
    clauses=new double*[rowsq];
    clauses[0]=new double[columnsq];
}

matrix::matrix(unsigned uRowsQ, unsigned uColumnsQ) {
    if(uRowsQ>0) rowsq=uRowsQ;
    else exit(EXIT_FAILURE);
    if(uColumnsQ>0) columnsq=uColumnsQ;
    else exit(EXIT_FAILURE);
    clauses=new double*[rowsq];
    for(unsigned i=0; i<rowsq; i++) {
        clauses[i]=new double[columnsq];
    }
}

matrix::matrix(matrix &right) {
    rowsq=right.rowsq;
    columnsq=right.columnsq;
    clauses=new double*[rowsq];
    for(unsigned i=0; i<rowsq; i++) {
        clauses[i]=new double[columnsq];
        for(unsigned j=0; j<columnsq; j++) {
            clauses[i][j]=right.clauses[i][j];
        }
    }
}

matrix& matrix::operator=(matrix &right) {
    rowsq=right.rowsq;
    columnsq=right.columnsq;
    clauses=new double*[rowsq];
    for(unsigned i=0; i<rowsq; i++) {
        clauses[i]=new double[columnsq];
        for(unsigned j=0; j<columnsq; j++) {
            clauses[i][j]=right.clauses[i][j];
        }
    }
    return *this;
}

matrix matrix::empty() {
    matrix c(rowsq, columnsq);
    for(unsigned i=0; i<c.rowsq; i++) {
        for(unsigned j=0; j<c.columnsq; j++) {
            c.clauses[i][j]=0;
        }
    }
    return c;
}

matrix matrix::identity() {
    matrix c(rowsq, columnsq);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(i==j) c.clauses[i][j]=1;
            else c.clauses[i][j]=0;
        }
    }
    return c;
}

unsigned matrix::operator==(matrix &right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 0;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(clauses[i][j]!=right.clauses[i][j]) return 0;
        }
    }
    return 1;
}

unsigned matrix::operator!=(matrix &right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 1;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(clauses[i][j]!=right.clauses[i][j]) return 1;
        }
    }
    return 0;
}

unsigned matrix::operator <(matrix &right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 0;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(clauses[i][j]>=right.clauses[i][j]) return 0;
        }
    }
    return 1;
}

unsigned matrix::operator <=(matrix &right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 0;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(clauses[i][j]>right.clauses[i][j]) return 0;
        }
    }
    return 1;
}

unsigned matrix::operator >(matrix &right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 0;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(clauses[i][j]<=right.clauses[i][j]) return 0;
        }
    }
    return 1;
}

unsigned matrix::operator >=(matrix &right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 0;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(clauses[i][j]<right.clauses[i][j]) return 0;
        }
    }
    return 1;
}

double matrix::getAccuracy() {
    if(!matrix::accuracy) {
        matrix::accuracy=0.000001;
    }
    return matrix::accuracy;
} 

void matrix::setAccuracy(double dAccuracy) {
    if(!matrix::accuracy) {
        matrix::accuracy=dAccuracy;
    }
}

unsigned matrix::approximateEquality(matrix& right) {
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) return 0;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(fabs(clauses[i][j]-right.clauses[i][j])>=matrix::getAccuracy()) {
                return 0;
            }
        }
    }
    return 1;
}

matrix matrix::operator+(matrix &right) {
    matrix c(rowsq, columnsq);
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) {
        throw new matrix_exception(MATRIX_UNSUBTRACTABLE_UNSUBLIMABLE);
    }
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            c.clauses[i][j]=clauses[i][j]+right.clauses[i][j];
        }
    }
    return c;
}

matrix matrix::operator-(matrix &right) {
    matrix c(rowsq, columnsq);
    if(rowsq!=right.rowsq || columnsq!=right.columnsq) {
        throw new matrix_exception(MATRIX_UNSUBTRACTABLE_UNSUBLIMABLE);
    }
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            c.clauses[i][j]=clauses[i][j]-right.clauses[i][j];
        }
    }
    return c;
}

matrix matrix::operator*(double right) {
    matrix c(rowsq, columnsq);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            c.clauses[i][j]=clauses[i][j]*right;
        }
    }
    return c;
}

matrix operator*(double left, matrix &right) {
    matrix c(right.rowsq, right.columnsq);
    for(unsigned i=0; i<right.rowsq; i++) {
        for(unsigned j=0; j<right.columnsq; j++) {
            c.clauses[i][j]=left*right.clauses[i][j];
        }
    }
    return c;
}

matrix matrix::operator*(matrix &right) {
    matrix c(rowsq, right.columnsq);
    if(columnsq!=right.rowsq) {
        throw new matrix_exception(MATRIX_UNMULTIPLIABLE_UNDIVISIBLE);
    }
    for(unsigned i=0; i<c.rowsq; i++) {
        for(unsigned j=0; j<c.columnsq; j++) {
            c.clauses[i][j]=0;
            for(unsigned k=0; k<right.rowsq; k++) {
                c.clauses[i][j]=c.clauses[i][j]+(clauses[i][k]*right.clauses[k][j]);
            }
        }
    }
    return c;
}

matrix matrix::powm(int y) {
    if(rowsq==columnsq) {
        matrix left, result;
        if(y<0) {
            left=inverse();
            result=inverse();
        }
        if(y>0) {
            left=*this;
            result=*this;
        }
        if(y==0) {
            result=identity();
        }
        int p=abs(y);
        for(int i=0; i<p-1; i++) {
            result=left*result;
        }
        return result;
    }
    else throw new matrix_exception(MATRIX_NON_SQUARE);
}

matrix matrix::operator/(double right) {
    matrix c(rowsq, columnsq);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            if(fabs(right)>=matrix::getAccuracy()) c.clauses[i][j]=clauses[i][j]/right;
            else throw new matrix_exception(MATRIX_DIVISION_MATRIX_BY_ZERO);
        }
    }
    return c;
}

matrix operator/(double left, matrix &right) {
    matrix c(right.rowsq, right.columnsq);
    for(unsigned i=0; i<right.rowsq; i++) {
        for(unsigned j=0; j<right.columnsq; j++) {
            if(fabs(right.clauses[i][j])>=matrix::getAccuracy()) c.clauses[i][j]=left/right.clauses[i][j];
            else throw new matrix_exception(MATRIX_DIVISOR_CONTENTS_ZERO);
        }
    }
    return c;
}

matrix matrix::operator/(matrix &right) {
    matrix c(rowsq, right.columnsq);
    if(columnsq!=right.rowsq) return c;
    for(unsigned i=0; i<c.rowsq; i++) {
        for(unsigned j=0; j<c.columnsq; j++) {
            c.clauses[i][j]=0;
            for(unsigned k=0; k<right.rowsq; k++) {
                if(fabs(right.clauses[k][j])>=matrix::getAccuracy()) c.clauses[i][j]=c.clauses[i][j]+(clauses[i][k]/right.clauses[k][j]);
                else throw new matrix_exception(MATRIX_DIVISOR_CONTENTS_ZERO);
            }
        }
    }
    return c;
}

unsigned matrix::getRowsQuantity() {
    return rowsq;
}

unsigned matrix::getColumnsQuantity() {
    return columnsq;
}

double** matrix::getMatrixAsArrayOfRows() {
    return clauses;
}

double* matrix::getMatrix() {
    double *dMatrix;
    dMatrix=new double[rowsq*columnsq];
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            *(dMatrix+i*columnsq+j)=clauses[i][j];
        }
    }
    return dMatrix;
}

void matrix::setArrayOfRows(double **dMatrix) {
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            clauses[i][j]=dMatrix[i][j];
        }
    }
}

void matrix::setMatrix(double *dMatrix) {
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            clauses[i][j]=*(dMatrix+i*columnsq+j);
        }
    }
}

double* matrix::getRow(unsigned rn) {
    if(rn<rowsq) return clauses[rn];
    else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
}

void matrix::setRow(unsigned rn, double *row) {
    for(unsigned j=0; j<columnsq; j++) {
        if(rn<rowsq) clauses[rn][j]=*(row+j);
        else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
    }
}

double* matrix::getColumn(unsigned cn) {
    double *column;
    column=new double[rowsq];
    for(unsigned i=0; i<rowsq; i++) {
        if(cn<columnsq) *(column+i)=clauses[i][cn];
        else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
    }
    return column;
}

void matrix::setColumn(unsigned cn, double *column) {
    for(unsigned i=0; i<rowsq; i++) {
        if(cn<columnsq) clauses[i][cn]=*(column+i);
        else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
        
    }
}

double matrix::getClause(unsigned rn, unsigned cn) {
    if(rn<rowsq && cn<columnsq) return clauses[rn][cn];
    else throw new matrix_exception(MATRIX_CLAUSE_OUT_OF_MATRIX);
}

void matrix::setClause(unsigned rn, unsigned cn, double clause) {
    if(rn<rowsq && cn<columnsq) clauses[rn][cn]=clause;
    else throw new matrix_exception(MATRIX_CLAUSE_OUT_OF_MATRIX);
}

void matrix::replaceRows(unsigned rn1, unsigned rn2) {
    double temp;
    if(rn1<rowsq && rn2<rowsq) {
        for(unsigned j=0; j<columnsq; j++) {
            temp=clauses[rn1][j];
            clauses[rn1][j]=clauses[rn2][j];
            clauses[rn2][j]=temp;
        }
    }
    else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
}

void matrix::replaceColumns(unsigned cn1, unsigned cn2) {
    double temp;
    if(cn1<columnsq && cn2<columnsq) {
        for(unsigned i=0; i<rowsq; i++) {
            temp=clauses[i][cn1];
            clauses[i][cn1]=clauses[i][cn2];
            clauses[i][cn2]=temp;
        }
    }
    else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
}

void matrix::multiplicateRowByNumber(unsigned rn, double number) {
    if(rn<rowsq) {
        for(unsigned j=0; j<columnsq; j++) {
            clauses[rn][j]=clauses[rn][j]*number;
        }
    }
    else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
}

void matrix::multiplicateColumnByNumber(unsigned cn, double number) {
    if(cn<columnsq) {
        for(unsigned i=0; i<rowsq; i++) {
            clauses[i][cn]=clauses[i][cn]*number;
        }
    }
    else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
}

void matrix::addOneRowToAnotherMultiplicated(unsigned rn1, unsigned rn2, double number) {
    if(rn1<rowsq && rn2<rowsq) {
        for(unsigned j=0; j<columnsq; j++) {
            clauses[rn1][j]=clauses[rn1][j]+(clauses[rn2][j]*number);
        }
    }
    else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
}

void matrix::addOneColumnToAnotherMultiplicated(unsigned cn1, unsigned cn2, double number) {
    if(cn1<columnsq && cn2<columnsq) {
        for(unsigned i=0; i<rowsq; i++) {
            clauses[i][cn1]=clauses[i][cn1]+(clauses[i][cn2]*number);
        }
    }
    else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
}

matrix matrix::deleteRowColumn(unsigned rn, unsigned cn) {
    double *temp;
    if(rn<rowsq && cn<columnsq) {
        unsigned temprowsq=rowsq-1, tempcolumnsq=columnsq-1;
        unsigned i, j, temprow, tempcolumn;
        temp=new double[temprowsq*tempcolumnsq];
        for((rn>0)?(i=0):i=1; i<rowsq; (i==rn-1)?(i+=2):i++) {
            if(i<rn) temprow=i;
            else temprow=i-1;
            for((cn>0)?(j=0):j=1; j<columnsq; (j==cn-1)?(j+=2):j++) {
                if(j<cn) tempcolumn=j;
                else tempcolumn=j-1;
                *(temp+temprow*tempcolumnsq+tempcolumn)=clauses[i][j];
            }
        }
        matrix mrcd(temprowsq, tempcolumnsq);
        mrcd.setMatrix(temp);
        delete [] temp;
        return mrcd;
    }
    else throw new matrix_exception(MATRIX_CLAUSE_OUT_OF_MATRIX);
}

matrix matrix::transpose() {
    matrix transposed(columnsq, rowsq);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            transposed.clauses[j][i]=clauses[i][j];
        }
    }
    return transposed;
}

double matrix::det() {
    if(rowsq==columnsq) {
        unsigned size=rowsq;
            if(size==1) {
                return clauses[0][0];
            }
            else if(size==2) {
             return clauses[0][0]*clauses[1][1]-clauses[0][1]*clauses[1][0];
            }
            else if(size>2) {
                int i=0;
                double result=0;
                for(unsigned j=0; j<size; j++) {
                    matrix temp=this->deleteRowColumn(i, j);
                    result=result+(clauses[i][j]*pow(-1, i+j+2)*temp.det());
                }
                return result;
            }
    }
    else {
        throw new matrix_exception(MATRIX_NON_SQUARE);
    }
}

double matrix::minor(unsigned rn, unsigned cn) {
    if(rn<rowsq && cn<columnsq) {
        matrix temp=this->deleteRowColumn(rn, cn);
        return temp.det();
    }
    else throw new matrix_exception(MATRIX_CLAUSE_OUT_OF_MATRIX);
}

double matrix::cofactor(unsigned rn, unsigned cn) {
    if(rn<rowsq && cn<columnsq) {
        matrix temp=this->deleteRowColumn(rn, cn);
        return pow(-1, rn+cn+2)*temp.det();
    }
    else throw new matrix_exception(MATRIX_CLAUSE_OUT_OF_MATRIX); 
}

matrix matrix::adjoint() {
    matrix a(rowsq, columnsq);
    if(rowsq==columnsq) {
        double *temp=new double[rowsq*columnsq];
        for(unsigned i=0; i<rowsq; i++) {
            for(unsigned j=0; j<columnsq; j++) {
                *(temp+i*columnsq+j)=this->cofactor(i, j);
            }
        }
        a.setMatrix(temp);
        a=a.transpose();
        delete [] temp;
        return a;
    }
    else throw new matrix_exception(MATRIX_NON_SQUARE);
}

matrix matrix::inverse() {
    double d=this->det();
    if(d!=0) return this->adjoint()/d;
    else throw new matrix_exception(MATRIX_NON_INVERSIBLE);
}

matrix matrix::absm() {
    matrix c(rowsq, columnsq);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            c.clauses[i][j]=fabs(clauses[i][j]);
        }
    }
    return c;
}

double matrix::m_norm() {
    double result=0, S;
    for(unsigned i=0; i<rowsq; i++) {
        S=0;
        for(unsigned j=0; j<columnsq; j++) {
            S=S+fabs(clauses[i][j]);
        }
        if(S>result) result=S;
    }
    return result;
}

double matrix::l_norm() {
    matrix c=transpose();
    double result=c.m_norm();
    return result;
}

double matrix::k_norm() {
    double S=0, result;
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            S=S+pow(fabs(clauses[i][j]), 2);
        }
    }
    result=sqrt(S);
    return result;
}

char* matrix::outputMatrix(const char greeting[60]) {
    char tempstr[29];
    char *output;
    strncpy(tempstr, "", 1);
    tempstr[28]='\0';
    output=new char[2*rowsq*(14*columnsq+1)+61];
    strncpy(output, "", 1);
    strncat(output, greeting, 60);
    strncat(output, "\r\n", 2);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            sprintf(tempstr, "%lf ", clauses[i][j]);
            strncat(output, tempstr, 28);
        }
        strncat(output, "\r\n", 2);
    }
    return output;
}

wchar_t* matrix::outputMatrix(const wchar_t greeting[60]) {
    wchar_t tempstr[29];
    wchar_t *output;
    wcsncpy(tempstr, L"", 1);
    tempstr[28]=L'\0';
    output=new wchar_t[2*rowsq*(14*columnsq+1)+61];
    wcsncpy(output, L"", 1);
    wcsncat(output, greeting, 60);
    wcsncat(output, L"\r\n", 2);
    for(unsigned i=0; i<rowsq; i++) {
        for(unsigned j=0; j<columnsq; j++) {
            swprintf(tempstr, L"%lf ", clauses[i][j]);
            wcsncat(output, tempstr, 28);
        }
        wcsncat(output, L"\r\n", 2);
    }
    return output;
}

char* matrix::outputMatrixRow(unsigned rn, const char greeting[60]) {
    char tempstr[29];
    char *output;
    if(rn<rowsq) {
        strncpy(tempstr, "", 1);
        output=new char[28*columnsq+3];
        strncpy(output, "", 1);
        strncat(output, greeting, 60);
        strncat(output, "\r\n", 2);
        for(unsigned j=0; j<columnsq; j++) {
            sprintf(tempstr, "%lf ", clauses[rn][j]);
            strncat(output, tempstr, 28);
        }
        strncat(output, "\r\n", 2);
        return output;
    }
    else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
}

wchar_t* matrix::outputMatrixRow(unsigned rn, const wchar_t greeting[60]) {
    wchar_t tempstr[29];
    wchar_t *output;
    if(rn<rowsq) {
        wcsncpy(tempstr, L"", 1);
        output=new wchar_t[28*columnsq+3];
        wcsncpy(output, L"", 1);
        wcsncat(output, greeting, 60);
        wcsncat(output, L"\r\n", 2);
        for(unsigned j=0; j<columnsq; j++) {
            swprintf(tempstr, L"%lf ", clauses[rn][j]);
            wcsncat(output, tempstr, 28);
        }
        wcsncat(output, L"\r\n", 2);
        return output;
    }
    else throw new matrix_exception(MATRIX_ROW_OUT_OF_MATRIX);
}

char* matrix::outputMatrixColumn(unsigned cn, const char greeting[60]) {
    char tempstr[29];
    char *output;
    if(cn<columnsq) {
        strncpy(tempstr, "", 1);
        output=new char[29*rowsq+1];
        strncpy(output, "", 1);
        strncat(output, greeting, 60);
        strncat(output, "\r\n", 2);
        for(unsigned i=0; i<rowsq; i++) {
            sprintf(tempstr, "%lf\r\n", clauses[i][cn]);
            strncat(output, tempstr, 29);
        }
        return output;
    }
    else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
}

wchar_t* matrix::outputMatrixColumn(unsigned cn, const wchar_t greeting[60]) {
    wchar_t tempstr[29];
    wchar_t *output;
    if(cn<columnsq) {
        wcsncpy(tempstr, L"", 1);
        output=new wchar_t[29*rowsq+1];
        wcsncpy(output, L"", 1);
        wcsncat(output, greeting, 60);
        wcsncat(output, L"\r\n", 2);
        for(unsigned i=0; i<rowsq; i++) {
            swprintf(tempstr, L"%lf\r\n", clauses[i][cn]);
            wcsncat(output, tempstr, 29);
        }
        return output;
    }
    else throw new matrix_exception(MATRIX_COLUMN_OUT_OF_MATRIX);
}

matrix::~matrix() {
    for(unsigned i=0; i<rowsq; i++) {
        delete [] clauses[i];
    }
    delete [] clauses;
}