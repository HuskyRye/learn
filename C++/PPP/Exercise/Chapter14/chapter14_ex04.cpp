/*
    4.(1).将 12.9.3 节中的 Link 类修改为模板，该模板以数值类型作为模板参数
      (2).然后使用 Link<God> 重做 chapter12_ex13
*/

#include "std_lib_facilities.h"

template<class T> struct Link {
    T value;
    Link<T>* prev;
    Link<T>* succ;
    Link(const T& v, Link<T>* p = nullptr, Link<T>* s = nullptr)
        :value { v }, prev { p }, succ { s } { }
};

template<typename T> Link<T>* insert(Link<T>* p, Link<T>* n)    // 在 p 之前插入 n，返回 n
{
    if (n == nullptr)
        return p;
    if (p == nullptr)
        return n;
    n->succ = p;
    if (p->prev)
        p->prev->succ = n;
    n->prev = p->prev;
    p->prev = n;
    return n;
}