#include "std_lib_facilities.h"

using Line = vector<char>;

class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    typedef forward_iterator_tag iterator_category;
    typedef char value_type;
    typedef size_t difference_type;
    typedef char* pointer;
    typedef char& reference;

    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        : ln { ll }, pos { pp } {}
    char& operator*() { return *pos; }
    Text_iterator& operator++();
    bool operator==(const Text_iterator& other) const
    {
        return ln == other.ln && pos == other.pos;
    }
    bool operator!=(const Text_iterator& other) const
    {
        return !(*this==other);
    }
};

Text_iterator& Text_iterator::operator++()
{
    ++pos;
    if (pos == (*ln).end()) {
        ++ln;
        pos = (*ln).begin();
    }
    return *this;
}

struct Document {
    list<Line> line;
    Document() { line.push_back(Line { }); }
    Text_iterator begin()
    {
        return Text_iterator(line.begin(), line.begin()->begin());
    }
    Text_iterator end()
    {
        auto last = line.end();
        --last;
        return Text_iterator(last, last->end());
    }
};

istream& operator>>(istream& is, Document& d)
{
    for (char ch; is.get(ch); ) {
        d.line.back().push_back(ch);    // 添加字符
        if (ch == '\n')
            d.line.push_back(Line { }); // 添加一行
    }
    if (d.line.back().size())
        d.line.push_back(Line { });     // 最后的空行
    return is;
}

void print(Document& d)
{
    for (auto p = d.begin(); p != d.end(); ++p)
        cout << *p;
}

void erase_line(Document& d, int n)
{
    if (n < 0 || d.line.size()-1 <= n)
        return;
    auto p = d.line.begin();
    advance(p, n);
    d.line.erase(p);
}

bool match(Text_iterator first, Text_iterator last, const string& s)
{
    string::const_iterator p;
    for (p = s.begin();
        p != s.end() && first != last && *p == *first;
        ++p, ++first) {
    }
    return p == s.end();
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s)
{
    if (s.size() == 0)
        return last;
    char first_char = s[0];
    while (true) {
        auto p = find(first, last, first_char);
        if (p == last || match(p, last, s))
            return p;
        first = ++p;
    }
}

int main()
{
    Document my_doc;
    cin >> my_doc;
    Text_iterator p = find_txt(my_doc.begin(), my_doc.end(), "secret\nhomestead");
    if (p==my_doc.end())
        cout << "not found\n";
    else {
        cout << "found!\n";
    }
    erase_line(my_doc, 0);

    print(my_doc);
}