#include <regex>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream in { "file.txt" };
    if (!in)
        cerr << "no file\n";

    string pattern = R"(\w{2}\s*\d{5}(-\d{4})?)";
    regex pat { pattern };
    cout << "pattern: " << R"(\w{2}\s*\d{5}(-\d{4})?)" << '\n';
    int lineno = 0;
    for (string line; getline(in, line); ) {
        ++lineno;
        smatch matches;
        if (regex_search(line, matches, pat)) {
            cout << lineno << ": " << matches[0] << '\n';
            if (matches.size() > 1 && matches[1].matched)
                cout << "\t: " << matches[1] << '\n';
        }
    }
}

