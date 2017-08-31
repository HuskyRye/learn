/*
	2.编写一个模板函数，该函数以 vector<T> vt 和 vector<U> vu 为参数并返回所有 vt[i]*vu[i] 之和
	注：用 C++11 <type_traits> std::common_type 声明返回值类型
*/

#include "std_lib_facilities.h"

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "{";
	for (int i = 0; i<v.size()-1; ++i)
		os << ' ' << v[i] << ',';
	os << ' ' << v[v.size()-1] << " }";
	return os;
}

template<class T, class U> typename common_type<T, U>::type f(const vector<T> vt, vector<U> vu)
{
	typename common_type<T, U>::type sum = 0;
	for (int i = 0; i < vt.size() && i < vu.size(); ++i)
		sum += vt[i] * vu[i];
	return sum;
}

int main()
try {
	vector<int> v1;
	for (int i = 0; i<10; ++i)
		v1.push_back(i);
	cout << "v1: " << v1 << "\n";
	vector<double> v2;
	for (int i = 0; i<8; ++i)
		v2.push_back(i*1.6);
	cout << "v2: " << v2 << "\n";
	cout << "f(v1,v2): " << f(v1, v2) << "\n";
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
	cerr << "Exception\n";
}
