#include "std_lib_facilities.h"

/*
Expression:
	Term
	Expression "+" Term
	Expression "-" Term
Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary
Primary:
	Number
	"(" Expression ")"
Number:
	floating-point-literal
*/

class Token {
public:
	char kind;
	double value;
};

double expression();
double term();
double primary();

class Token_stream {
public:
	Token get();
	void putback(Token t);
private:
	bool full { false };
	Token buffer;
};

Token Token_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}
	char ch;
	cin >> ch;
	switch (ch) {
	case ';': case 'q': case '(': case ')': case '+': case '-': case '*': case '/':
		return Token { ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token { '8', val };
	}
	default:
		error("Bad token");
	}
}

void Token_stream::putback(Token t)
{
	if (full)
		error("putback() into a full buffer");
	buffer = t;
	full = true;
}

Token_stream ts;

/*
double expression1()
{
	double left = expression();
	Token t = get_token();
	switch (t.kind) {
	case '+':
		return left + term();
	case '-':
		return left - term();
	default:
		return left;
	}
}

double expression2()
{
	double left = term();
	Token t = get_token();
	switch (t.kind) {
	case '+':
		return left + expression();
	case '-':
		return left - expression();
	default:
		return left;
	}
}

double expression3()
{
	double left = term();
	Token t = get_token();
	while (t.kind == '+' || t.kind == '-') {
		if (t.kind == '+')
			left += term();
		else
			left -= term();
		t = get_token();
	}
	return left;
}
*/

double expression()
{
	double left = term();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double term()
{
	double left = primary();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		/*
		case '%':
			left %= primary();
			t = get_token();
			break;
		*/
		default:
			ts.putback(t);
			return left;
		}
	}
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')')
			error("')' expected");
		return d;
	}
	case '8':
		return t.value;
	default:
		error("primary expected");
	}
}

int main()
try {

//	while (cin)
//		cout << '=' << expression() << '\n';

	double val = 0;
	while (cin) {
		Token t = ts.get();
		if (t.kind == 'q')
			break;
		if (t.kind == ';')
			cout << '=' << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open();
	return 2;
}