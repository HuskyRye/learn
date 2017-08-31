#include "std_lib_facilities.h"

// Drill 1
template<typename T> struct S
{	
	S() : val { T{} } {}	// Drill 2
	S(T v) : val { v } {}
	T& get();				// Drill 5
	const T& get() const;	// Drill 11
	void set(const T&);		// Drill 9
	T& operator=(const T&);	// Drill 10
private:					// Drill 7
	T val;
};

// Drill 6
template<typename T> T& S<T>::get()
{
	return val;
}

// Drill 9
template<typename T> void S<T>::set(const T& d)
{
	val = d;
}

// Drill 10
template<typename T> T& S<T>::operator=(const T& d)
{
	val = d;
	return val;
}

// Drill 11
template<typename T> const T& S<T>::get() const
{
	return val;
}

// Drill 13
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "{ ";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i<v.size()-1)
			os << ',';
		os << ' ';
	}
	os << '}';
	return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v)
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.clear(ios_base::failbit);
		error("bad start of vector");
	}
	T temp;
	vector<T> v_temp;
	while (cin >> temp >> ch && ch == ',') {
		v_temp.push_back(temp);
	}
	if (ch != '}') {
		is.clear(ios_base::failbit);
		error("bad end of vector");
	}
	v_temp.push_back(temp);
	v = v_temp;
	return is;
}

// Drill 12
template<typename T> void read_val(T& v)
{
	cin >> v;
}

int main()
try {
	// Drill 3
	S<int> s_int(3);
	S<char> s_char('x');
	S<double> s_dbl(3.14);
	S<string> s_strg("String3");
	S<vector<int>> s_v_int(vector<int>(5, 3));

	// Drill 4
	// std::cout << "s_int: " << s_int.val << "\n";
	// std::cout << "s_char: " << s_char.val << "\n";
	// std::cout << "s_dbl: " << s_dbl.val << "\n";
	// std::cout << "s_strg: " << s_strg.val << "\n";
	// for (int i = 0; i<s_v_int.val.size(); ++i)
	//     std::cout << "s_v_int[" << i << "]: " << s_v_int.val[i] << "\n";

	// Drill 8
	std::cout << "s_int: " << s_int.get() << "\n";
	std::cout << "s_char: " << s_char.get() << "\n";
	std::cout << "s_dbl: " << s_dbl.get() << "\n";
	std::cout << "s_strg: " << s_strg.get() << "\n";
	for (int i = 0; i<s_v_int.get().size(); ++i)
		std::cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

	// Drill 9
	s_int.set(9);
	s_char.set('y');
	s_dbl.set(9.14);
	s_strg.set("String9");
	s_v_int.set(vector<int>(5, 9));
	std::cout << "\ns_int: " << s_int.get() << "\n";
	std::cout << "s_char: " << s_char.get() << "\n";
	std::cout << "s_dbl: " << s_dbl.get() << "\n";
	std::cout << "s_strg: " << s_strg.get() << "\n";
	for (int i = 0; i<s_v_int.get().size(); ++i)
		std::cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

	// Drill 10
	s_int = 10;
	s_char = 'z';
	s_dbl = 10.14;
	s_strg = "String10";
	s_v_int = vector<int>(5, 10);
	std::cout << "\ns_int: " << s_int.get() << "\n";
	std::cout << "s_char: " << s_char.get() << "\n";
	std::cout << "s_dbl: " << s_dbl.get() << "\n";
	std::cout << "s_strg: " << s_strg.get() << "\n";
	for (int i = 0; i<s_v_int.get().size(); ++i)
		std::cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

	// Drill 11
	const S<int> c_s_int(11);
	const S<char> c_s_char('a');
	const S<double> c_s_dbl(11.14);
	const S<string> c_s_strg("String11");
	const S<vector<int>> c_s_v_int(vector<int>(5, 11));
	std::cout << "\nc_s_int: " << c_s_int.get() << "\n";
	std::cout << "c_s_char: " << c_s_char.get() << "\n";
	std::cout << "c_s_dbl: " << c_s_dbl.get() << "\n";
	std::cout << "c_s_strg: " << c_s_strg.get() << "\n";
	for (int i = 0; i<c_s_v_int.get().size(); ++i)
		std::cout << "c_s_v_int[" << i << "]: " << c_s_v_int.get()[i] << "\n";

	// 13
	std::cout << "\ns_int: ";
	read_val(s_int.get());
	std::cout << "s_char: ";
	read_val(s_char.get());
	std::cout << "s_dbl: ";
	read_val(s_dbl.get());
	std::cout << "s_strg: ";
	read_val(s_strg.get());
	std::cout << "\ns_int: " << s_int.get() << "\n";
	std::cout << "s_char: " << s_char.get() << "\n";
	std::cout << "s_dbl: " << s_dbl.get() << "\n";
	std::cout << "s_strg: " << s_strg.get() << "\n\n";

	// 14
	std::cout << "\ns_v_int: ";
	read_val(s_v_int.get());
	std::cout << "\ns_v_int: " << s_v_int.get() << "\n";

	keep_window_open("~");
	return 0;
}
catch (exception& e) {
	cerr << "Exception: " << e.what() << "\n";
	keep_window_open("~");
}
catch (...) {
	cerr << "Exception\n";
	keep_window_open("~");

}
