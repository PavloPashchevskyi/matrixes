/* 
 * File:   main.cpp
 * Author: ppd
 *
 * Created on 27 марта 2015 г., 15:42
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include "matrix.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned uRowsQ, uColumnsQ;
    double clause;
    double *clauses;
    double *columns;
    unsigned digitsq;
    double accuracy;
	unsigned i, j;
    cout<<"Input quantity of digits after decimal point enough to matrixes approximate calculation: ";
    cin>>digitsq;
    accuracy=1./pow(10, digitsq);
    matrix::setAccuracy(accuracy);
    cout<<"Input left matrix rows quantity: ";
    cin>>uRowsQ;
    cout<<"Input left matrix columns quantity: ";
    cin>>uColumnsQ;
    matrix m1(uRowsQ, uColumnsQ);
    clauses=new double[uRowsQ*uColumnsQ];
    cout<<"Please, input left matrix:"<<endl;
    for(i=0; i<m1.getRowsQuantity(); i++) {
        /*for(unsigned j=0; j<m1.getColumnsQuantity(); j++) {
            scanf("%lf", (clauses+i*uColumnsQ+j));
            //scanf("%lf", &clause);
            //m1.setClause(i, j, clause);
        }*/
        columns=new double[uColumnsQ];
        for(j=0; j<m1.getColumnsQuantity(); j++) {
            cin>>*(columns+j);
        }
        m1.setRow(i, columns);
        delete [] columns;
    }
    //m1.setMatrix(clauses);
    //delete [] clauses;
    cout<<"Input right matrix rows quantity: ";
    cin>>uRowsQ;
    cout<<"Input right matrix columns quantity: ";
    cin>>uColumnsQ;
    matrix m2(uRowsQ, uColumnsQ);
    cout<<"Please, input right matrix:"<<endl;
    for(i=0; i<m2.getRowsQuantity(); i++) {
        for(j=0; j<m2.getColumnsQuantity(); j++) {
            cin>>clause;
            m2.setClause(i, j, clause);
        }
    }
        matrix m22=m1.absm();
        puts(m22.outputMatrix("Absolute value of left matrix:"));
        double m_norm=m1.m_norm();
        cout<<"m-norm of left matrix: "<<m_norm<<endl;
        double l_norm=m1.l_norm();
        cout<<"l-norm of left matrix: "<<l_norm<<endl;
        double k_norm=m1.k_norm();
        cout<<"k-norm of left matrix: "<<k_norm<<endl;
    try {
        double det=m1.det();
        cout<<"Determinant of left matrix: "<<det<<endl;
        matrix m18=m1.adjoint();
        puts(m18.outputMatrix("Adjoint matrix to left:"));
        matrix m19=m1.inverse();
        puts(m19.outputMatrix("Inverse to left matrix:"));
        matrix m20=m1*m1.inverse();
        puts(m20.outputMatrix("Initial and inverse left matrixes multiplicated:"));
        matrix m3=m1+m2;
        puts(m3.outputMatrix("Sublimation:"));
        matrix m4=m2-m1;
        puts(m4.outputMatrix("Subtraction:"));
        cout<<"Input number needed to multiplicate by matrix: ";
        cin>>clause;
        matrix m5=m1*clause;
        puts(m5.outputMatrix("Multiplication by number:"));
        matrix m6=clause*m1;
        puts(m6.outputMatrix("Multiplication number by matrix:"));
        matrix m7=m1*m2;
        puts(m7.outputMatrix("Multiplication:"));
        matrix m21=m1.powm(-2);
        puts(m21.outputMatrix("Left matrix involution:"));
        matrix m8=m1/clause;
        puts(m8.outputMatrix("Division matrix by number:"));
        matrix m9=clause/m1;
        puts(m9.outputMatrix("Division number by matrix:"));
        matrix m10=m1/m2;
        puts(m10.outputMatrix("Division:"));
        matrix m11=m1;
        m11.replaceRows(1, 4);
        puts(m11.outputMatrix("Replacing of left matrix rows:"));
        matrix m12=m1;
        m12.replaceColumns(1, 4);
        puts(m12.outputMatrix("Replacing of left matrix columns:"));
        matrix m13=m1;
        m13.multiplicateRowByNumber(1, 2);
        puts(m13.outputMatrix("Left matrix with row multiplicated:"));
        matrix m14=m1;
        m14.multiplicateColumnByNumber(1, 2);
        puts(m14.outputMatrix("Left matrix with column multiplicated:"));
        matrix m15=m1;
        m15.addOneRowToAnotherMultiplicated(1, 2, 4);
        puts(m15.outputMatrix("Left matrix with row added to another multiplicated:"));
        matrix m16=m1;
        m16.addOneColumnToAnotherMultiplicated(1, 2, 4);
        puts(m16.outputMatrix("Left matrix with column added to another multiplicated:"));
        matrix m17=m1.transpose();
        puts(m17.outputMatrix("Transposed left matrix:"));
        puts(m1.outputMatrixRow(1, "Left matrix first row:"));
        puts(m1.outputMatrixColumn(1, "Left matrix first column:"));
        cout<<"Matrix clause: "<<m1.getClause(1, 1)<<endl;
    }
    catch(matrix_exception &me) {
        cerr<<me.errorCode()<<" "<<me.error()<<endl;
    }
    return 0;
}

