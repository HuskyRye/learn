#include <algorithm>
#include "14.vector.h"

vector::vector(const vector& arg)
	:sz { arg.sz }, elem { new double[arg.sz] }
{
	std::copy(arg.elem, arg.elem+sz, elem);
}

vector& vector::operator=(const vector& a)
{
	if (this == &a)
		return *this;
	if (a.sz <= space) {
		std::copy(a.elem, a.elem+sz, elem);
		sz = a.sz;
		return *this;
	}

	double* p = new double[a.sz];
	std::copy(a.elem, a.elem+sz, p);
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

vector::vector(vector&& a)
	:sz { a.sz }, elem { a.elem }
{
	a.sz = 0;
	a.elem = nullptr;
}

vector& vector::operator=(vector&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}

void vector::reserve(int newalloc)
{
	if (newalloc <= space)
		return;
	double* p = new double[newalloc];
	std::copy(elem, elem+sz, p);
	delete[] elem;
	elem = p;
	space = newalloc;
}

void vector::resize(int newsize)
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i)
		elem[i] = 0;
	sz = newsize;
}

void vector::push_back(double d)
{
	if (space == 0)
		reserve(8);
	else if (sz == space)
		reserve(space*2);
	elem[sz] = d;
	++sz;
}