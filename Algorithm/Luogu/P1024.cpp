/*
	Author: 刘臣轩
	Date: 2017.10.25
	Source: NOIP 2001
*/

#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

double a, b, c, d;
inline double f(double x)
{
	return (a*pow(x, 3) + b*pow(x, 2) + c*x + d);
}

void search(double l, double r)
{
	double m = (l + r) / 2;
	double fm = f(m);
	if (l + 0.001 > r || fm == 0) {
		cout << fixed << setprecision(2) << m << ' ';
		return;
	}
	if (f(l) == 0.0) {
		cout << fixed << setprecision(2) << l << ' ';
		return;
	}
	if (f(l) * fm < 0)
		search(l, m);
	else if (fm * f(r) < 0)
		search(m, r);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> a >> b >> c >> d;

	for (int i = -100; i <= 100; ++i)
		if (f(i) * f(i + 1) <= 0)
			search(i, i + 1);
}