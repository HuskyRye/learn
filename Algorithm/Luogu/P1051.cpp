/*
	Author: 刘臣轩
	Date: 2017.11.5
	Source: NOIP 2005 提高
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

struct Student
{
	string name;
	int scholar;
}student[110];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> student[i].name;
		int final_grade, class_grade, paper;
		char student_leader, western_student;
		cin >> final_grade >> class_grade >> student_leader >> western_student >> paper;
		student[i].scholar = 0;
		if (final_grade > 80 && paper >= 1)
			student[i].scholar += 8000;
		if (final_grade > 85 && class_grade > 80)
			student[i].scholar += 4000;
		if (final_grade > 90)
			student[i].scholar += 2000;
		if (final_grade > 85 && western_student == 'Y')
			student[i].scholar += 1000;
		if (class_grade > 80 && student_leader == 'Y')
			student[i].scholar += 850;
		sum += student[i].scholar;
	}
	stable_sort(student, student + n, [](const Student& a, const Student& b) { return a.scholar > b.scholar; });
	cout << student[0].name << endl << student[0].scholar << endl;
	cout << sum << endl;
	return 0;
}