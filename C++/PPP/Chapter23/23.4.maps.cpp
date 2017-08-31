#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

using namespace std;

typedef vector<string>::const_iterator Line_iter;

class Message {
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) : first { p1 }, last { p2 } {}
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
};

using Mess_iter = vector<Message>::const_iterator;

struct Mail_file {
    string name;
    vector<string> lines;
    vector<Message> m;

    Mail_file(const string& n);
    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

// 在一个 Message 中查找发件人姓名，找到返回 true，将姓名放入 s 中
bool find_from_addr(const Message& m, string& s);

// 返回 Message 的主题
string find_subject(const Message* m);

int main()
{
    Mail_file mfile { "my-mail-file.txt" };

    multimap<string, const Message*> sender;

    for (const Message& m : mfile) {
        string s;
        if (find_from_addr(m, s))
            sender.insert(make_pair(s, &m));
    }
    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for (auto p = pp.first; p != pp.second; ++p) {
        cout << find_subject(p->second) << '\n';
    }
}

Mail_file::Mail_file(const string & n)
{
    ifstream in { n };      // 打开文件
    if (!in) {
        cerr << "no " << n << '\n';
        exit(1);
    }
    for (string s; getline(in, s); )
        lines.push_back(s);
    auto first = lines.begin();
    for (auto p = lines.begin(); p != lines.end(); ++p) {
        if (*p == "----") {
            m.push_back(Message(first, p));
            first = p+1;
        }
    }
}

int is_prefix(const string& s, const string& p)
// p 是 s 的一部分
{
    int n = p.size();
    if (string(s, 0, n) == p)
        return n;
    return 0;
}

bool find_from_addr(const Message& m, string& s)
{
    for (const auto& x : m)
        if (int n = is_prefix(x, "From: ")) {
            s = string(x, n);
            return true;
        }
    return false;
}

string find_subject(const Message * m)
{
    for (Line_iter p = m->begin(); p != m->end(); ++p)
        if (int n = is_prefix(*p, "Subject: "))
            return string(*p, n);
    return "";
}