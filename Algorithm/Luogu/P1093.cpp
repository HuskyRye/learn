/*
	Author: 刘臣轩
	Date: 2017.11.5
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
	int chinese;
	int sum;
	int id;
}student[310];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		student[i].chinese = a;
		student[i].sum = a + b + c;
		student[i].id = i;
	}
	stable_sort(student + 1, student + n + 1, [](const Student& a, const Student& b) { return a.sum != b.sum ? a.sum > b.sum : a.chinese > b.chinese; });
	for (int i = 1; i <= 5; ++i)
		cout << student[i].id << ' ' << student[i].sum << endl;
	return 0;
}