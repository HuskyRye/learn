#include "std_lib_facilities.h"

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void print_array(ostream& os, int a[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << '\n';
}

void f(int a[], int n)
{
	int la[10];
	copy(ga, ga+10, la);
	print_array(cout, la, 10);
	int* p { new int[n] };
	memcpy(p, a, n*sizeof(int));
	print_array(cout, p, 10);
	delete[] p;
	p = nullptr;
}

int main()
try {
	f(ga, 10);

	int aa[10] = { 1 };
	for (int i = 1; i < 10; ++i)
		aa[i] = aa[i-1]*(i+1);
	f(aa, 10);
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
