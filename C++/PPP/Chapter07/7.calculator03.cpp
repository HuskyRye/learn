/*
	FileName:	calculator.cpp
	Author:		刘臣轩
	Version：	3.0
	Date:		2017-8-18
	History：
		<Author>	<Date>		<Version>	<Description>
		 刘臣轩	   2017-8-18	   2.0		实现了简单计算器功能
		 刘臣轩	   2017-8-18	   3.0		添加功能，代码清理
	Description:
		简单计算器程序
		从 cin 读入，输出到 cout

		输入文法如下：
		Statement:
			Expression
			Print
			Quit
		Print:
			;
		Quit:
			q
		Expression:
			Term
			Expression + Term
			Expression - Term
		Term:
			Primary
			Term * Primary
			Term / Primary
			Term % Primary
		Primary:
			Number
			( Expression )
			+ Primary
			- Primary
		Number:
			floating-point-literal
*/

#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

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
	void ignore(char c);
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
	case print: case quit:
	case '(': case ')':
	case '+': case '-': case '*': case '/': case '%': 
		return Token { ch };
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token { number, val };
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

void Token_stream::ignore(char c)
// precondition: c 代表单词类型
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	char ch = 0;
	while (cin >> ch)
		if (ch == c)
			return;
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
		case '%':
		{
			double d = primary();
			if (d == 0)
				error("divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
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
	case number:
		return t.value;
	case '+':
		return primary();
	case '-':
		return -primary();
	default:
		error("primary expected");
	}
}

void clean_up_mess()
{
	/*
	while (true) {
		Token t = ts.get();
		if (t.kind == print)
			return;
	}
	*/
	ts.ignore(print);
}

void calculate()
{
	while (cin)
	try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print)
			t = ts.get();
		if (t.kind == quit)
			return;
		ts.putback(t);
		cout << result << expression() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();
	}
}

/*
void calculate()
{
	double val = 0;
	cout << "> ";
	while (cin) {
		Token t = ts.get();
		if (t.kind == 'q')
			break;
		else if (t.kind == ';') {
			cout << "= " << val << '\n';
			cout << "> ";
		}
		else
			ts.putback(t);
		val = expression();
	}
}
*/

int main()
try {
	calculate();
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open("~");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open("~");
	return 2;
}
