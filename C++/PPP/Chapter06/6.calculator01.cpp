#include "std_lib_facilities.h"

int main1()
{
	cout << "Please enter expression (we can handle + and - ): ";
	int lval = 0;
	int rval;
	char op;
	int res;
	cin >> lval >> op >> rval;

	if (op == '+')
		res = lval + rval;
	else if (op == '-')
		res = lval - rval;
	cout << "Result: " << res << '\n';
	keep_window_open();
	return 0;
}

int main2()
{
	cout << "Please enter expression (we can handle +, -, * and /)\n ";
	cout << "add an x to end expression (e.g., 1+2*3x): ";
	int lval = 0;
	int rval;
	cin >> lval;
	if (!cin)
		error("no first operand");
	for (char op; cin >> op; ) {
		if (op != 'x')
			cin >> rval;
		if (!cin)
			error("no second operand");
		switch (op) {
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default:
			cout << "Result: " << lval << '\n';
			keep_window_open();
			return 0;
		}
	}
	error("bad expression");
}

class Token {
public:
	char kind;
	double value;
};

Token get_token();

vector<Token> tok;

int main()
{
	while (cin) {
		Token t = get_token();
		tok.push_back(t);
	}
}