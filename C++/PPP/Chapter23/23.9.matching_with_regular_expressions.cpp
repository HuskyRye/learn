#include "std_lib_facilities.h"

int main()
try {
    ifstream in { "table.txt" };
    
    string line;
    int lineno = 0;

    regex header(R"(^[\w ]+(	[\w ]+)*$)");               // header line
    regex row(R"(^([\w ]+)(	\d+)(	\d+)(	\d+)$)");   // data line

    if (getline(in, line)) {
        smatch matches;
        if (!regex_match(line, matches, header))
            throw runtime_error("no header");
    }
    int boys = 0;
    int girls = 0;

    while (getline(in, line)) {
        ++lineno;
        smatch matches;
        if (!regex_match(line, matches, row))
            cerr << "bad line: " << lineno << '\n';

        if (in.eof())
            cout << "at eof\n";

        int curr_boy = stoi(matches[2].str());
        int curr_girl = stoi(matches[3].str());
        int curr_total = stoi(matches[4].str());

        if (curr_boy+curr_girl != curr_total)
            error("bad row sum\n");

        if (matches[1] == "Alle klasser") {
            if (curr_boy != boys)
                error("boys don't add up\n");
            if (curr_girl != girls)
                error("girls don't add up\n");
            if (!(in>>ws).eof())
                error("characters after total line");
            return 0;
        }
        boys += curr_boy;
        girls += curr_girl;
    }
    error("didn't find total line");

}
catch (exception& e) {
    cerr << e.what() << '\n';
}