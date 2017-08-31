/*
    1.编写程序，读取一个文本文件，将其中的字母都转换成小写，生成一个新文件
*/

#include "std_lib_facilities.h"

int main()
{
    ifstream ist { "chapter11_ex01_in.txt" };
    if (!ist)
        error("can't open input file ", "chapter11_ex01_in.txt");

    ofstream ost { "chapter11_ex01_out.txt" };
    if (!ost)
        error("can't open output file ", "chapter11_ex01_in.txt");

    string line;
    while (getline(ist, line)) {
        for (char& ch : line)
            ch = tolower(ch);
        ost << line << '\n';
    }
}