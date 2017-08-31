#include "std_lib_facilities.h"

// 1.4
void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
		os << a[i] << '\n';
}

// 1.7
void print_array(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
		os << a[i] << '\n';
}

// 1.10
void print_vector(ostream& os, vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
		os << v[i] << '\n';
}

int main1()
{
	// 1.1
	int* p = new int[10];

	// 1.2
	cout << "*** 2 ***\n";
	for (int i = 0; i < 10; ++i)
		cout << p[i] << '\n';

	// 1.3
	delete[] p;

	// 1.5
	cout << "*** 5 ***\n";
	p = new int[10];
	for (int i = 0; i < 10; ++i)
		p[i] = 100+i;
	print_array10(cout, p);
	delete[] p;

	// 1.6
	cout << "*** 6 ***\n";
	p = new int[11];
	for (int i = 0; i < 11; ++i) {
		p[i] = 100+i;
		cout << p[i] << '\n';
	}
	delete[] p;

	// 1.8
	cout << "*** 8 ***\n";
	p = new int[20];
	for (int i = 0; i < 20; ++i)
		p[i] = 100+i;
	print_array(cout, p, 20);
	delete[] p;

	// 1.10
	cout << "*** 10 ***\n";
	vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(100+i);
	print_vector(cout, v);

	vector<int> v2;
	for (int i = 0; i < 11; ++i)
		v2.push_back(100+i);
	print_vector(cout, v2);

	vector<int> v3;
	for (int i = 0; i < 20; ++i)
		v3.push_back(100+i);
	print_vector(cout, v3);

	return 0;
}

int main2()
{
	// 2.1
	int a = 7;
	int* p1 = &a;

	// 2.2
	cout << "*** 2 ***\n";
	cout << p1 << ", " << *p1 << '\n';

	// 2.3
	int b[7];
	for (int i = 0; i < 7; ++i)
		b[i] = pow(2, i);
	int* p2 = b;

	// 2.4
	cout << "*** 4 ***\n";
	cout << p2 << '\n';
	print_array(cout, p2, 7);

	// 2.5
	int* p3 { p2 };

	// 2.6
	p2 = p1;

	// 2.7
	p2 = p3;

	// 2.8
	cout << "*** 8 ***\n";
	cout << p1 << ", " << *p1 << '\n';
	cout << p2 << '\n';
	print_array(cout, p2, 7);

	// 2.10
	int c[10];
	for (int i = 0; i < 10; ++i)
		b[i] = pow(2, i);
	p1 = c;

	// 2.11
	int d[10];
	p2 = d;

	// 2.12
	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	return 0;
}

int main()
{
	main2();
	keep_window_open();
	return 0;
}