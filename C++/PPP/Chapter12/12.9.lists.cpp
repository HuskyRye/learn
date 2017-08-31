// 链表实例

#include "std_lib_facilities.h"

class Link {
public:
	string value;
	Link(const string&v, Link* p = nullptr, Link*s = nullptr)
		: value { v }, prev { p }, succ { s } {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s);
	const Link* find(const string& s) const;

	Link* advance(int n) const;

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};


Link* Link::insert(Link* n)	// 在 this 前插入 n，返回 n
{
	if (n == nullptr)
		return this;
	if (this == nullptr)
		return n;
	n->succ = this;
	if (prev)
		prev->succ = n;
	n->prev = this->prev;
	prev = n;
	return n;
}

Link* Link::add(Link * n)	// 在 this 的后面插入 n， 返回 n
{
	if (this == nullptr)
		return n;
	if (n == nullptr)
		return this;
	n->prev = this;
	if (succ)
		succ->prev = n;
	n->succ = succ;
	succ = n;
	return n;
}

Link* Link::erase()		// 删除 this， 返回 this 的后继
{
	if (this == nullptr)
		return nullptr;
	if (succ)
		succ->prev = prev;
	if (prev)
		prev->succ = succ;
	return succ;
}

Link* Link::find(const string& s)	// 在链表中查找 s
{
	Link* p = this;
	while (p) {
		if (p->value == s)
			return p;
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const string & s) const
{
	const Link* p = this;
	while (p) {
		if (p->value == s)
			return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n) const	// 获得第 n 个后继
{
	const Link* p = this;
	if (p == nullptr)
		return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr)
				return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr)
				return nullptr;
			p = p->prev;
		}
	}
	return const_cast<Link*>(p);
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->value;
		if (p = p->next())
			cout << ", ";
	}
	cout << " }";
}

/*
Link* insert(Link* p, Link* n)
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

// chapter12_ex11
Link* add(Link* p, Link* n)	// 在 p 的后面插入 n， 返回 n
{
	if (p == nullptr)
		return n;
	if (n == nullptr)
		return p;
	n->prev = p;
	if (p->succ)
		p->succ->prev = n;
	n->succ = p->succ;
	p->succ = n;
	return n;
}

Link* erase(Link* p)		// 删除 p， 返回 p 的后继
{
	if (p == nullptr)
		return nullptr;
	if (p->succ)
		p->succ->prev = p->prev;
	if (p->prev)
		p->prev->succ = p->succ;
	return p->succ;
}

Link* find(Link* p, const string& s)	// 在链表 p 中查找 s
{
	while (p) {
		if (p->value == s)
			return p;
		p = p->succ;
	}
	return nullptr;
}

Link* advance(Link* p, int n)	// 获得第 n 个后继
{
	if (p == nullptr)
		return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr)
				return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr)
				return nullptr;
			p = p->prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->value;
		if (p = p->succ)
			cout << ", ";
	}
	cout << " }";
}
*/

int main()
{
	Link* norse_gods = new Link { "Thor" };
	/*
	norse_gods = insert(norse_gods, new Link { "Odin" });
	norse_gods = insert(norse_gods, new Link { "Freia" });
	print_all(norse_gods);
	cout << '\n';
	*/
	norse_gods = norse_gods->insert(new Link { "Odin" });
	norse_gods = norse_gods->insert(new Link { "Freia" });
	print_all(norse_gods);
	cout << '\n';
	keep_window_open();
	return 0;
}