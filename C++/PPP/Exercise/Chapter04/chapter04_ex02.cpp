/*
	2.修改 4.6.3 的程序使其总能输出中值
*/

#include "std_lib_facilities.h"

int main()
{
	vector<double> temps;
	for (double temp; cin >> temp;) {
		temps.push_back(temp);
	}

	double sum = 0;
	for (int x : temps)
		sum += x;
	cout << "Average temperature: " << sum/temps.size() << '\n';

	sort(temps);

	double median;
	if (temps.size()%2 == 1)
		median = temps[temps.size()/2];
	else
		median = (temps[temps.size()/2] + temps[temps.size()/2 - 1])/2;
	cout << "Median temperature: " << median << '\n';
	return 0;
}