/*
	Author: 刘臣轩
	Date: 2017.11.11 
*/ 

#include <iostream>
#include <cmath>
using namespace std;
int gcd(int x, int y) {
	if (y == 0)
		return x;
	return gcd(y, x%y);
}
int main() {
	ios::sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	int xy = x*y;
	int ans = 0;
	for (int i = x; i <= sqrt(xy); i += x)
		if (xy%i == 0 && gcd(i, xy/i) == x)
			++ans;
	cout << ans*2 << endl;
	return 0;
}
