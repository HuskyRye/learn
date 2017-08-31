#include "std_lib_facilities.h"

template<typename Elem> struct Link {
    Link* prev;
    Link* succ;
    Elem val;
};

template<typename Elem>
class list {
public:
    class iterator;     // 成员类型：迭代器（嵌套类）
    iterator begin();   // 指向首元素的迭代器
    iterator end();     // 指向尾元素之后的迭代器

    iterator insert(iterator p, const Elem& v);     // 将 v 插入链表中 p 之后的位置
    iterator erase(iterator p);                     // 从链表中删除 p
    
    void push_back(const Elem& v);      // 将 v 插入链表末尾
    void push_front(const Elem& v);     // 将 v 插入链表头
    void pop_front();       // 删除首元素
    void pop_back();        // 删除尾元素

    Elem& front();          // 获取首元素
    Elem& back();           // 获取尾元素
};

template<typename Elem>     // request Element<Elem>()
class list<Elem>::iterator {
    Link<Elem>* curr;       // 当前链接
public:
    iterator(Link<Elem>* p) : curr { p } { }
    iterator& operator++() { curr = curr->succ; return *this; }
    iterator& operator--() { curr = curr->prev; return *this; }
    Elem& operator*() { return curr->val; }

    bool operator==(const iterator&b) const { return curr == b.curr; }
    bool operator!=(const iterator&b) const { return curr != b.curr; }
};

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
        if (*high < *p)
            high = p;
    return high;
}

template<typename C>
using Iterator = typename C::iterator;

template<typename C>
using Value_type = typename C::value_type;

void f()
{
    list<int> lst;
    for (int x; cin >> x; )
        lst.push_front(x);
    list<int>::iterator p = high(lst.begin(), lst.end());
    if (p == lst.end())
        cout << "The list is empty";
    else
        cout << "the highest value is " << *p << '\n';
}

void print2(const vector<double>& v, list<double>& lst)
{
    for (double x : v)
        cout << x << '\n';
    for (double x : lst)
        cout << x << '\n';
}

template<typename T>
void user(vector<T>& v, list<T>& lst)
{
    for (auto p = v.begin(); p != v.end(); ++p)
        cout << *p << '\n';
    auto q = find(lst.begin(), lst.end(), T { 42 });
}