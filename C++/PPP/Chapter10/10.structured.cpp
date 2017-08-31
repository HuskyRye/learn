/*
{ year 1990 }
{ year 1991 { month jun }}
{ year 1992 { month jan (1 0 61.5)} {month feb (1 1 64) (2 2 65.2)}}
{ year 2000
{ month feb (1 1 68) (2 3 66.66) (1 0 67.2)}
{ month dec (15 15 -9.2) (15 14 -8.8£© £¨14 0 -2)}
}
*/

#include "std_lib_facilities.h"

const int not_a_month = -1;
const int not_a_reading = -7777;

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

struct Day {
	vector<double> hour { vector<double>(24, not_a_reading) };
};

struct Month {
	int month { not_a_month };
	vector<Day> day { 32 };		// waste day[0]
};

struct Year {
	int year;
	vector<Month> month { 12 };
};

struct Reading {
	int day;
	int hour;
	double temperature;
};

istream& operator>>(istream& is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}
	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')')
		error("bad reading");
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r)
{
	if (r.day < 1 || r.day > 31)
		return false;
	if (r.hour < 0 || r.hour > 23)
		return false;
	if (r.temperature < implausible_min || r.temperature > implausible_max)
		return false;
	return true;
}

vector<string> month_input_tbl = {
	"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"
};

int month_to_int(string s)
{
	for (int i = 0; i < 12; ++i)
		if (month_input_tbl[i] == s)
			return i;
	return -1;
}

vector<string> month_print_tbl = {
	"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"
};

string int_to_month(int i)
{
	if (i < 0 || i > 11)
		error("bad month index");
	return month_print_tbl[i];
}

istream& operator>>(istream& is, Month& m)
{
	char ch = 0;
	if (is >> ch && ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;
	if (!is || month_marker != "month")
		error("bad start of month");
	m.month = month_to_int(mm);
	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is >> r; ) {
		if (is_valid(r)) {
			if (m.day[r.day].hour[r.hour] != not_a_reading)
				++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature;
		}
		else
			++invalids;
	}
	if (invalids)
		error("invalid readings in month ", invalids);
	if (duplicates)
		error("duplicate readings in month ", duplicates);
	end_of_loop(is, '}', "bad end of month");
	return is;
}

istream& operator>>(istream& is, Year& y)
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	string year_marker;
	int yy;
	is >> year_marker >> yy;

	if (!is || year_marker != "year")
		error("bad start of year");
	y.year = yy;

	for (Month m; is >> m; ) {
		y.month[m.month] = m;
		m = Month {};
	}

	end_of_loop(is, '}', "bad end of year");
	return is;
}

void print_month(ostream& ost, Month& m)
{
	ost << "{ month " << int_to_month(m.month) << ' ';
	for (int i = 1; i < 32; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (m.day[i].hour[j] != not_a_reading) {
				ost << '(' << i << ' ' << j << ' ' << m.day[i].hour[j] << ')';
			}
		}
	}
	ost << '}';
}

void print_year(ostream& ost, Year& y)
{
	ost << "{ year " << y.year << ' ';
	for (Month& m : y.month) {
		if (m.month != not_a_month)
			print_month(ost, m);
	}
	ost << "}\n";

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

		cout << "Please enter name of output file: ";
		string oname;
		cin >> oname;
		ofstream ost { oname };
		if (!ost)
			error("can't open output file ", oname);

	vector<Year> ys;
	while (true) {
		Year y;
		if (!(ist >> y))
			break;
		ys.push_back(y);
	}
	cout << "read " << ys.size() << "years of readings\n";
	for (Year& y : ys)
		print_year(ost, y);

}