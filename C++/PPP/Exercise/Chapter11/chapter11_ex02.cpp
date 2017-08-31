/*
    2.编写程序，给定一个文件名和一个单词，输出文件中包含该单词的每一行及其行号
*/

#include "std_lib_facilities.h"

int main()
{
    ifstream ist { "chapter11_ex02_in.txt" };
    if (!ist)
        error("can't open input file ", "chapter11_ex01_in.txt");

    ofstream ost { "chapter11_ex02_out.txt" };
    if (!ost)
        error("can't open output file ", "chapter11_ex01_in.txt");

    string line;
    int linenumber = 0;
    while (getline(ist, line)) {
        linenumber++;
        if (line.find("html")==string::npos)
            continue;
        ost << setw(4) << linenumber  << " | " << line << '\n';
    }
}