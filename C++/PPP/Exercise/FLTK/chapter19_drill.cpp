#include "std_lib_facilities.h"

class B1 {
public:
	virtual void vf() const { cout << "B1::vf()\n"; }
	void f() const { cout << "B1::f()\n"; }
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
	void vf() const override { cout << "D1::vf()\n"; }
	void f() const { cout << "D1::f()\n"; }
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2::pvf()\n"; }
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	void pvf() override { cout << s; }
	string s { "D21::d21\n" };
};

class D22 : public B2 {
public:
	void pvf() override { cout << n << '\n'; }
	int n { 22 };
};

void f(B2& b2)
{
	b2.pvf();
}

int main()
{
	/*
	B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();
	*/

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);

	keep_window_open();
	return 0;
}