#include <algorithm>
#include "14.3.vector.h"

template<typename T, typename A>
vector<T, A>::vector(const vector& arg)
	:sz { arg.sz }, elem { new T[arg.sz] }
{
	std::copy(arg.elem, arg.elem+sz, elem);
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(const vector<T, A>& a)
{
	if (this == &a)
		return *this;
	if (a.sz <= space) {
		std::copy(a.elem, a.elem+sz, elem);
		sz = a.sz;
		return *this;
	}

	T* p = new T[a.sz];
	std::copy(a.elem, a.elem+sz, p);
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

template<typename T, typename A>
vector<T, A>::vector(vector&& a)
	:sz { a.sz }, elem { a.elem }
{
	a.sz = 0;
	a.elem = nullptr;
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}

template<typename T, typename A>
void vector<T, A>::reserve(int newalloc)
{
	if (newalloc <= space)
		return;
	T* p = alloc.allocate(newalloc);
	for (int i = 0; i < sz; ++i)
		alloc.construct(&p[i], elem[i]);
	for (int i = 0; i < sz; ++i)
		alloc.destroy(&elem[i]);
	alloc.deallocate(elem, space);
	elem = p;
	space = newalloc;
}

template<typename T, typename A>
void vector<T, A>::resize(int newsize, T def = T())
{
	reserve(newsize);
	for (int i = sz; i < newsize; ++i)
		alloc.construct(&elem[i], val);
	for (int i = newsize; i < sz; ++i)
		alloc.destroy(&elem[i]);
	sz = newsize;
}

template<typename T, typename A>
void vector<T, A>::push_back(const T& d)
{
	if (space == 0)
		reserve(8);
	else if (sz == space)
		reserve(space*2);
	alloc.construct(&elem[sz], val);
	++sz;
}