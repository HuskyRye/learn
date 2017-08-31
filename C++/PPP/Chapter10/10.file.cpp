#include "std_lib_facilities.h"

struct Reading {
	int hour;
	double temperature;
};

int main1()
{
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist { iname };
	if (!ist)
		error("can't open input file ", iname);

	cout << "Please enter name of output file: ";
	string oname;
	cin >> oname;
	ofstream ost { oname };
	if (!ost)
		error("can't open output file ", oname);

	vector<Reading> temps;
	int hour;
	double temperature;
	while (ist >> hour >> temperature) {
		if (hour < 0 || 23 < hour)
			error("hour out of range");
		temps.push_back(Reading { hour, temperature });
	}

	for (int i = 0; i < temps.size(); ++i) {
		ost << '(' << temps[i].hour << ',' << temps[i].temperature << ")\n";
	}
}

// error
void fill_vector(istream& ist, vector<int>& v, char terminator)
{
	for (int i; ist >> i; )
		v.push_back(i);
	if (ist.eof())
		return;

	ist.clear();
	char c;
	ist >> c;
	if (c != terminator) {
		ist.unget();
		ist.clear(ios_base::failbit);
	}
}

void skip_to_int()
{
	if (cin.fail()) {
		cin.clear();
		for (char ch; cin >> ch; ) {
			if (isdigit(ch) || ch == '-') {
				cin.unget();
				return;
			}
		}
	}
	error("no input");
}

int get_int();
int get_int(int low, int high);

int get_int()
{
	int n = 0;
	while (true) {
		if (cin >> n)
			return n;
		cout << "Sorry, that was not a number, please try again\n";
		skip_to_int();
	}
}

int get_int(int low, int high)
{
	cout << "Please enter an integer in the range " << low << " to " << "high" << " (inclusive):\n";
	while (true) {
		int n = get_int();
		if (low <= n && n <= high)
			return n;
		cout << "Sorry " << n << " is not in the [" << low << ':' << high << "] range, please try again\n";
	}
}

int get_int(int low, int high, const string& greeting, const string& sorry)
{
	cout << greeting << ": [" << low << ':' << high << "]\n";
	while (true) {
		int n = get_int();
		if (low <= n && n <= high)
			return n;
		cout << sorry << ": [" << low << ':' << high << "]\n";
	}
}

int main2()
{
	int n = get_int(1, 10);
	int m = get_int(2, 300);
	int strength = get_int(1, 10, "enter strength", "Not in range, try again");
	return 0;
}

// user-defined
ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

istream& operator>>(istream& is, Date& dd)
{
	int y, m, d;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> y >> ch2 >> m >>  ch3 >> d >> ch4;
	if (!is)
		return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
		is.clear(ios_base::failbit);
		return is;
	}
	dd = Date { y, Date::Month(m), d };
	return is;
}

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

int main3(ifstream& ist)
{
	// somewhere: ist 处于 bad 状态时抛出一个异常
	ist.exceptions(ist.exceptions()|ios_base::badbit);
	for (My_type var; ist >> var; ) {
		// 检查并操作
	}
	end_of_loop(ist, '|', "bad termination of file");
	// eof
}