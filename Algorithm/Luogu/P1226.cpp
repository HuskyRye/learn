/*
	Author: 刘臣轩
	Date: 2017.11.7
*/

#include <iostream>
using namespace std;

long long b, p, k;
long long quickpow(long long a, long long b) {
	if (b == 0)
		return 1;
	long long r = quickpow(a, b / 2);
	r *= r;
	if (b % 2)
		r *= a;
	return r%k;
}

int main() {
	cin >> b >> p >> k;
	cout << b << '^' << p << " mod " << k << '=' << quickpow(b, p)%k << endl;
	return 0;
}