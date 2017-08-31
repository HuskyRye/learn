#include "std_lib_facilities.h"

int main()
{
	double d;
	string unit;
	double smallest = 0;
	double biggest = 0;
	double sum = 0;
	bool is_first = true;
	vector<double> vals;
	while (cin >> d >> unit) {
		if (d < 0) {
			cout << "invalid number";
			continue;
		}
		if (unit == "cm")
			d /= 100;
		else if (unit == "m")
			;
		else if (unit == "in")
			d *= 0.0254;
		else if (unit == "ft")
			d *= (12*0.0254);
		else {
			cout << "invalid unit\n";
			continue;
		}
		if (d < smallest || is_first) {
			smallest = d;
			cout << "the smallest so far\n";
		}
		if (d > biggest || is_first) {
			biggest = d;
			cout << "the biggest so far\n";
		}
		vals.push_back(d);
		sum += d;
		is_first = false;
	}
	cout << "smallest value: " << smallest << " m\n"
		<< "biggest value: " << biggest << " m\n"
		<< "number of values: " << vals.size() << '\n'
		<< "sum of values: " << sum << " m\n";
	sort(vals.begin(), vals.end());
	cout << "values: " << '\n';
	for (int i = 0; i < vals.size(); ++i)
		cout << vals[i] << " m\n";
	return 0;
}