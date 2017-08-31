#include "std_lib_facilities.h"

vector<string> conjuction { "and", "or", "but" };
vector<string> noun { "birds", "fish", "C++" };
vector<string> verb { "rules", "fly", "swim" };

bool is_conjuction(string& s)
{
	for (string& x : conjuction) {
		if (x == s)
			return true;
	}
	return false;
}

bool is_noun(string& s)
{
	for (string& x : noun) {
		if (x == s)
			return true;
	}
	return false;
}

bool is_verb(string& s)
{
	for (string& x : verb) {
		if (x == s)
			return true;
	}
	return false;
}

bool is_sentence()
{
	string w;
	cin >> w;
	if (!is_noun(w))
		return false;

	string w2;
	cin >> w2;
	if (!is_verb(w2))
		return false;

	string w3;
	cin >> w3;

	if (w3 == ".")
		return true;
	else if (!is_conjuction(w3))
		return false;
	else
		return is_sentence();
}

int main()
try {
	while (cin) {
		bool b = is_sentence();
		if (b)
			cout << "OK\n";
		else
			cout << "not OK\n";
	}
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception" << '\n';
	keep_window_open();
	return 2;
}