/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <map>
using namespace std;

struct node
{
	char value;
	node* leftchild;
	node* rightchild;
} tree[30];
int top = -1;
map<char, int> m;
void preorder(node* p) {
	if (p == NULL)
		return;
	cout << p->value;
	preorder(p->leftchild);
	preorder(p->rightchild);
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	char a, b, c;
	for (int i = 1; i < n; ++i) {
		cin >> a >> b >> c;
		if (m.count(a) == 0) {
			tree[++top].value = a;
			m[a] = top;
		}
		if (m.count(b) == 0 && b != '*') {
			tree[++top].value = b;
			m[b] = top;
		}
		if (m.count(c) == 0 && c != '*') {
			tree[++top].value = c;
			m[c] = top;
		}
		if (b != '*')
			tree[m[a]].leftchild = &tree[m[b]];
		if (c != '*')
			tree[m[a]].rightchild = &tree[m[c]];
	}
	preorder(tree);
	return 0;
}