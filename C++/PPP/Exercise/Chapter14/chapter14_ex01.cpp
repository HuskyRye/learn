/*
	1.编写一个模板函数 f()，该函数能够将一个 vector<T> 的元素加到另一个 vector<T> 的元素
*/

#include "std_lib_facilities.h"

template<class T> void f(vector<T>& a, vector<T>& b)
{
	for (int i = 0; i < a.size() && i < b.size(); ++i)
		a[i] += b[i];
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "{";
	for (int i = 0; i<v.size()-1; ++i)
		os << ' ' << v[i] << ',';
	os << ' ' << v[v.size()-1] << " }";
	return os;
}

int main()
try {
	vector<int> v1;
	for (int i = 0; i<10; ++i)
		v1.push_back(i);
	cout << "v1: " << v1 << "\n";
	vector<int> v2;
	for (int i = 0; i<8; ++i)
		v2.push_back(i);
	cout << "v2: " << v2 << "\n";
	f(v1, v2);
	cout << "After: " << v1 << "\n\n";

	v2.push_back(15);
	v2.push_back(16);
	v2.push_back(17);
	cout << "New v2: " << v2 << "\n";
	f(v1, v2);
	cout << "After: " << v1 << "\n\n";

	vector<string> vs1;
	vs1.push_back("one");
	vs1.push_back("two");
	vs1.push_back("three");
	vs1.push_back("four");
	cout << "vs1: " << vs1 << "\n";
	vector<string> vs2;
	vs2.push_back(" ONE");
	vs2.push_back(" TWO");
	vs2.push_back(" THREE");
	cout << "vs2: " << vs2 << "\n";
	f(vs1, vs2);
	cout << "After: " << vs1 << "\n";

}
catch (exception& e) {
	cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
	cerr << "Exception\n";
}
