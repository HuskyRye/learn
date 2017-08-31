/*
	18.解一元二次方程
*/

#include "std_lib_facilities.h"

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b*b-4*a*c;
    if (delta < 0)
        cout << "no root";
    double x1 = (-b+sqrt(delta))/2*a;
    double x2 = (-b-sqrt(delta))/2*a;
    cout << "x1 = " << x1 << ", " << "x2 = " << x2 << '\n';
}