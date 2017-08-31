#include "std_lib_facilities.h"

struct X {
	int val;
	void out(const string& s, int nv)
	{
		cerr << this << "->" << s << ": " << val << " (" << nv << ")\n";
	}

	X() { out("X()", 0); val = 0; }
	X(int v) { val = v; out("X(int)", v); }
	X(const X& x) { val = x.val; out("X(X&) ", x.val); }
	X& operator=(const X& a)
	{
		out("X::operator=()", a.val);
		val = a.val;
		return *this;
	}
	~X() { out("~X()", 0); }
};

X glob(2);

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

int main()
{
	X loc { 4 };
	cout << "----------\n";
	X loc2 { loc };
	cout << "----------\n";
	loc = X { 5 };
	cout << "----------\n";
	loc2 = copy(loc);
	cout << "----------\n";
	loc2 = copy2(loc);
	cout << "----------\n";
	X loc3 { 6 };
	cout << "----------\n";
	X& r = ref_to(loc);
	cout << "----------\n";
	delete make(7);
	cout << "----------\n";
	delete make(8);
	cout << "----------\n";
	vector<X> v(4);
	cout << "----------\n";
	XX loc4;
	cout << "----------\n";
	X* p = new X { 9 };
	cout << "----------\n";
	delete p;
	cout << "----------\n";
	X* pp = new X[5];
	cout << "----------\n";
	delete[] pp;
}