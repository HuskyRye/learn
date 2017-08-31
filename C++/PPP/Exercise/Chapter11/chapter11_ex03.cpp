/*
    3.编写程序，将文件中的元音都删除。
    例如 "Once upon a time!" -> "nc pn tm!"
*/

#include "std_lib_facilities.h"

bool isvowel(char ch)
{
    static const string vowel { "AaEeIiOoUu" };
    if (vowel.find(ch) != string::npos)
        return true;
    return false;
}

void disemvowels(string& s)
{
    string res;
    for (char& x : s)
        if (!isvowel(x))
            res += x;
    s = res;
}

int main()
{
    ifstream ist { "chapter11_ex03_in.txt" };
    if (!ist)
        error("can't open input file ", "chapter11_ex01_in.txt");

    ofstream ost { "chapter11_ex03_out.txt" };
    if (!ost)
        error("can't open output file ", "chapter11_ex01_in.txt");

    string line;
    int linenumber = 0;
    while (getline(ist, line)) {
        linenumber++;
        disemvowels(line);
        ost << setw(4) << linenumber  << " | " << line << '\n';
    }
}