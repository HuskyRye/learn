/*
	Author: 刘臣轩
	Date: 2017.11.8
*/

#include <iostream>
#include <string>
using namespace std;

void preorder(int n, const string& in, const string& post) {
	if (n == 0)
		return;
	cout << post[n-1];
	int p = in.find(post[n-1]);
	preorder(p, in, post);
	preorder(n-1-p, in.substr(p+1), post.substr(p));
}

int main() {
	string in, post;
	cin >> in >> post;
	preorder(in.size(), in, post);
}