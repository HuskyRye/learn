#include <regex>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    regex pattern;
    string pat;
    cout << "enter patter: ";
    getline(cin, pat);

    try {
        pattern = pat;
        cout << "pattern: " << pat << '\n';
    }
    catch (bad_exception) {
        cout << pat << " is not a valid regular expression\n";
        exit(1);
    }

    cout << "now enter lines:\n";
    int lineno = 0;
    for (string line; getline(cin, line); ) {
        ++lineno;
        smatch matches;
        if (regex_match(line, matches, pattern)) {
            cout << "line: " << lineno << ": " << line << '\n';
            for (int i = 0; i < matches.size(); ++i)
                cout << "\tmatches[" << i << "]: " <<matches[i] << '\n';
        }
        else
            cout << "didn't match\n";
    }
}