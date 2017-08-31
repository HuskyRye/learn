#include "std_lib_facilities.h"
#include "Matrix.h"

using namespace Numeric_lib;

void f(int n1, int n2, int n3)
{
    Matrix<double, 1> ad1(n1);
    Matrix<int, 1> ai1(n1);
    ad1(7) = 0;     // Fortran style
    ai1[7] = 0;     // C style
    Matrix<double, 2> ad2(n1, n2);
    Matrix<double, 3> ad3(n1, n2, n3);
    ad2(3, 4) = 7.5;
    ad3[3][4][5] = 9.2;
}

void init(Matrix<int, 2>& a)
{
    for (int i = 0; i < a.dim1(); ++i)
        for (int j = 0; j < a.dim2(); ++j)
            a(i, j) = 10*i+j;
}

void print(Matrix<int, 2>& a)
{
    for (int i = 0; i < a.dim1(); ++i)
        for (int j = 0; j < a.dim2(); ++j)
            cout << a(i, j) << '\t';
    cout << '\n';
}

void some_function(double* p, int n)
{
    double val[] = { 1.2, 2.3, 3.4, 4.5 };
    Matrix<double> data(p, n);
    Matrix<double> constatns(val);
}