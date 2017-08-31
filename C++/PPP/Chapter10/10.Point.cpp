#include "std_lib_facilities.h"

struct Point
{
	double x;
	double y;
};

void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail()) {
		ist.clear();
		char ch;
		if (ist>>ch && ch == term)
			return;
		error(message);
	}
}

istream& operator>>(istream& ist, Point& p)
{
	char ch;
	ist >> ch;
	if (ch != '(') {
		ist.unget();
		ist.clear(ios_base::failbit);
		return ist;
	}
	double x;
	double y;
	char ch2;
	ist >> x >> ch >> y >> ch2;
	if (!ist) {
		return ist;
	}
	if (ch != ',' || ch2 != ')') {
		ist.clear(ios_base::failbit);
		return ist;
	}
	p.x = x;
	p.y = y;
	return ist;
}

void print_point(ostream& ost, const Point& p)
{
	ost << '(' << p.x << ',' << p.y << ')' << '\n';
}

int main()
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist { iname };
	if (!ist)
		error("can't open input file ", iname);

	ist.exceptions(ist.exceptions()|ios_base::badbit);

	ofstream ost { "mydata.txt" };
	if (!ost)
		error("can't open output file mydata.txt");

	vector<Point> original_points;
	for (int i = 0; i < 7; ++i) {
		Point p;
		if (!(ist >> p))
			break;
		original_points.push_back(p);
	}

	for (Point& p : original_points) {
		print_point(ost, p);
	}

	ist.close();
	ost.close();
}