#include "std_lib_facilities.h"

// 整数
int main1()
{
	cout << 1234 << "\t(decimal)\n"				// 1234	(decimal)
		<< hex << 1234 << "\t(hexadecimal)\n"	// 4d2	(hexadecimal)
		<< oct << 1234 << "\t(octal)\n"			// 2322	(octal)
		<< 1234 << "\n";						// 2322

	cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';		// 1234	4d2	2322	
	cout << showbase << dec;
	cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';		// 1234	0x4d2	02322
	cout << noshowbase;

	int a, b, c, d;
	cin >> a >> hex >> b >> oct >> c >> d;							// 1234 4d2 2322 2322
	cout << dec << a << ' ' << b << ' ' << c << ' ' << d << ' ';	// 1234 1234 1234 1234

	cin.unsetf(ios::dec);
	cin.unsetf(ios::oct);
	cin.unsetf(ios::hex);

	cin >> a >> b >> c >> d;										// 1234 0x4d2 02322 02322
	cout << dec << a << ' ' << b << ' ' << c << ' ' << d << ' ';	// 1234 1234 1234 1234
	return 0;
}

// 浮点数
int main2()
{
	cout << 1234.56789 << "\t\t(defaultflat)\n"				// 1234.57		(general)
		<< fixed << 1234.56789 << "\t(fixed)\n"				// 1234.567890	(fixed)
		<< scientific << 1234.56789 << "\t(scientific)\n";	// 1.234568e+003(scienfitic)
	cout << 1234.56789 << '\n';								// 1.234568e+003	

// 精度
	cout << defaultfloat << setprecision(5)		// 1234.6  1234.56789  1.23457e+003
		<< 1234.56789 << '\t'					// 数字的个数  小数点后数字个数 小数点后数字个数
		<< fixed << 1234.56789 << '\t'			
		<< scientific << 1234.56789 << '\n';

	cout << defaultfloat << setprecision(8)		// 1234.5679  1234.56789000  1.23456789e+003
		<< 1234.56789 << '\t'					// 数字的个数  小数点后数字个数 小数点后数字个数
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';
	return 0;
}

// 域
int main3()
{
	cout << 123456
		<< '|' << setw(4) << 123456 << '|'
		<< setw(8) << 123456 << '|'
		<< 123456 << "|\n";					// 123456|123456|  123456|123456|

	return 0;
}

int main4()
{
	string name { "test.txt" };
	ofstream ofs { name, ios_base::app };
	fstream fs { name, ios_base::in|ios_base::out };
	return 0;
}

// 二进制I/O
int main5()
{
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs { iname, ios_base::binary };
	if (!ifs)
		error("can't open input file ", iname);

	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs { oname, ios_base::binary };
	if (!ofs)
		error("can't open output file ", oname);

	vector<int> v;

	for (int x; ifs.read(as_bytes(x), sizeof(int)); )
		v.push_back(x);

	for (int x : v)
		ofs.write(as_bytes(x), sizeof(int));

	return 0;
}

// 在文件中定位
int main6()
{
	string name { "test.txt" };
	fstream fs { name };
	if (!fs)
		error("can't open ", name);

	fs.seekg(5);	// 移动读位置到第5（第6个字符处）
	char ch;
	fs >> ch;

	fs.seekp(1);	// 移动写位置到 1
	fs << 'y';
}

// 字符串流
double str_to_double(string s)
{
	istringstream is { s };
	double d;
	is >> d;
	if (!is)
		error("double format error: ", s);
	return d;
}

// 面向行的输入
int main7()
{
	string name;
	getline(cin, name);
	cout << name << '\n';
}

// 非标准分隔符
int main8()
{
	string line;
	for (char& ch : line)
		switch (ch) {
		case ';': case '.': case ',': case '?': case '!':
			ch = ' ';
		}
	stringstream ss(line);
	vector<string> vs;
	for (string word; ss >> word; )
		vs.push_back(word);
}

class Punct_stream {
public:
	Punct_stream(istream &is) : source{is}, sensitive{true}{}
	void whitespace(const string& s) { white = s; }
	void add_white(char c) { white += c; }
	bool is_whitespace(char c);
	void case_sensitive(bool b) { sensitive = b; }
	bool is_case_sensitive() { return sensitive; }

	Punct_stream& operator>>(string& s);
	operator bool();
private:
	istream& source;		// 符号源
	istringstream buffer;	// 处理格式
	string white;
	bool sensitive;
};

Punct_stream & Punct_stream::operator>>(string & s)
{
	while (!(buffer>>s)) {
		if (buffer.bad() || !source.good())
			return *this;
		buffer.clear();

		string line;
		getline(source, line);

		for (char& ch : line)
			if (is_whitespace(ch))
				ch = ' ';
			else if (!sensitive)
				ch = tolower(ch);
		buffer.str(line);
	}
	return *this;
}

bool Punct_stream::is_whitespace(char c)
{
	for (char w : white)
		if (c == w)
			return true;
	return false;
}

Punct_stream::operator bool()
{
	return !(source.fail() || source.bad()) && source.good();
}

int main()
{
	Punct_stream ps { cin };
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
	ps.case_sensitive(false);

	cout << "please enter words\n";
	vector<string> vs;
	for (string word; ps >> word; )
		vs.push_back(word);
	sort(vs.begin(), vs.end());
	for (int i = 0; i < vs.size(); ++i)
		if (i == 0 || vs[i] != vs[i-1])
			cout << v[i] << '\n';
}