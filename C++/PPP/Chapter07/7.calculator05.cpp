/*
	FileName:	calculator.cpp
	Author:		刘臣轩
	Version：	5.0
	Date:		2017-8-19
	History：
		<Author>	<Date>		<Version>	<Description>
		 刘臣轩	   2017-8-18	   2.0		实现了简单计算器功能
		 刘臣轩	   2017-8-18	   3.0		添加功能，代码清理
		 刘臣轩	   2017-8-19	   4.0		对变量的支持
		 刘臣轩	   2017-8-19	   5.0		支持 Function(Expression)
	Description:
		简单计算器程序
		从 cin 读入，输出到 cout

		输入文法如下：
		Calculation:
			Statement
			Print
			Quit
			Calculation Statement
		Statement:
			Declaration
			Expression
		Declaration:
			"let" Name = Expression
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
			Name
			Name = Expression
			Function ( Expression )
			( Expression )
			+ Primary
			- Primary
		Function:
			sqrt
			sin
			cos
			tan
		Name:
			[a-zA-Z][a-zA-Z_0-9]*
		Number:
			floating-point-literal
*/

#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const char function = 'f';
const string sqrkey = "sqrt";
const string sinkey = "sin";
const string coskey = "cos";
const string tankey = "tan";

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch) : kind { ch } {}
	Token(char ch, double val) : kind { ch }, value { val } {}
	Token(char ch, string s) : kind { ch }, name { s } {}
};

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

double get_value(string s)
// 返回 name 为字符串 s 的 Variable 对应的值
{
	for (const Variable& v : var_table)
		if (v.name == s)
			return v.value;
	error("get: undefined variable ", s);
}

void set_value(string s, double d)
// 设置 name 为字符串 s 的 Variable 对应的值为 d
{
	for (Variable& v : var_table) {
		if (v.name == s) {
			v.value = d;
			return;
		}
	}
	error("set: undefined variable ", s);
}

bool is_declared(string var)
// var 是否已经在 var_table 中
{
	for (const Variable& v : var_table)
		if (v.name == var)
			return true;
	return false;
}

double define_name(string var, double val)
// 将 (var, val) 加入 var_table 中
{
	if (is_declared(var))
		error(var, " declared twice");
	var_table.push_back(Variable { var, val });
	return val;
}

double statement();
double declaration();
double expression();
double term();
double primary();
double fun(const string& s, double d);

class Token_stream {
public:
	Token get();
	void putback(Token t);
	void ignore(char c);
	Token_stream() : full {false}{}
private:
	bool full { false };
	Token buffer { 0 };
};

Token_stream ts;

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
	case '=':
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
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalnum(ch) || ch == '_'))
				s += ch;
			cin.putback(ch);
			if (s == declkey)
				return Token { let };
			else if (s == sqrkey || s == sinkey || s == coskey || s == tankey)
				return Token { function, s };
			return Token{name, s};
		}
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

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name)
		error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=')
		error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

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
	case name:
	{
		Token t2 = ts.get();
		if (t2.kind != '=') {
			ts.putback(t2);
			return get_value(t.name);
		}
		double d = expression();
		set_value(t.name, d);
		return d;
	}
	case function:
	{
		Token t2 = ts.get();
		if (t2.kind != '(')
			error("'(' expected");
		double d = expression();
		t2 = ts.get();
		if (t2.kind != ')')
			error("')' expected");
		return fun(t.name, d);
	}
	case '+':
		return primary();
	case '-':
		return -primary();
	default:
		error("primary expected");
	}
}

double fun(const string& s, double d)
{
	if (s == sqrkey)
		return sqrt(d);
	else if (s == sinkey)
		return sin(d*get_value("pi")/180);
	else if (s == coskey)
		return cos(d*get_value("pi")/180);
	else if (s == tankey)
		return tan(d*get_value("pi")/180);
	else
		error("unexpected function");
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
		cout << result << statement() << '\n';
	}
	catch (exception& e) {
		cerr << e.what() << '\n';
		clean_up_mess();
	}
}

int main()
try {
	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);

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
