/*
    4.编写程序，提示用户输入几个数，可以使用不同的数制，对八进制和十六进制分别使用 0 和 0x 前缀进行输入。
    程序能正确解释这些数值，并将它们转换为十进制格式。随后按列对其输出这些数值.
    // 0x43 hexadecimal converts to     67 decimal
    // 0123 octal       converts to     83 decimal
    //   65 decimal     converts to     65 decimal
*/

#include "std_lib_facilities.h"

void converts(vector<string>& v)
{
    int length = 0;
    for (const string& s : v)
        if (s.length() > length)
            length = s.length();
    int val;
    for (const string& s : v) {
        cout << setw(length) << s;
        if (s.length() > 1) {
            if (s[1] == 'x' || s[1] == 'X') {
                cout << " hexadecimal ";
                val = stoi(s, nullptr, 16);
            }
            else if (s[0] == '0') {
                cout << " octal       ";
                val = stoi(s, nullptr, 8);
            }
            else {
                cout << " decimal     ";
                val = stoi(s);
            }
        }
        else {
            cout << " decimal     ";
            val = stoi(s);
        }
        cout << "converts to " << setw(4) << val << " decimal.\n";
    }

}

int main()
{
    cout << "Enter some integers in any (hex,octal,decimal) base (\"quit\" to finish input loop):\n";
    vector<string> v;
    string num;
    while (cin >> num && num != "quit")
        v.push_back(num);
    converts(v);
    return 0;
}