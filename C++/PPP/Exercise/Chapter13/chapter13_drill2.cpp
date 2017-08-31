#include "std_lib_facilities.h"

vector<int> gv { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void print_vector(vector<int>& v)
{
	for (int x : v)
		cout << x << '\n';
}

void f(vector<int>& v)
{
	vector<int> lv(v.size());
	lv = gv;
	print_vector(lv);
	vector<int> lv2 { v };
	print_vector(lv2);
}

int main()
try {
	f(gv);
	vector<int> vv { 1 };
	for (int i = 1; i < 10; ++i)
		vv.push_back(vv[i-1]*(i+1));
	f(vv);
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}