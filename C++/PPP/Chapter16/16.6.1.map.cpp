#include "std_lib_facilities.h"
#include <map>
#include <numeric>

// example
void example()
{
    // unordered_map
    unordered_map<string, double> dow_price = {
        { "MMM", 81.86 },
        { "AA", 34.69 },
        { "MO", 54.45 },
    };

    map<string, double> dow_weight = {
        { "MMM", 5.8549 },
        { "AA", 2.4808 },
        { "MO", 3.8940 },
    };

    map<string, string> dow_name = {
        { "MMM", "3M Co." },
        { "AA", "Alcoa Inc." },
        { "MO", "Altria Group Inc." },
    };

    for (const auto&p : dow_price) {
        const string& symbol = p.first;
        cout << symbol << '\t' << p.second << '\t' << dow_name[symbol] << '\n';
    }
    double dji_index = inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0, plus<double>(),
        [](const pair<string, double>&a, const pair<string, double>& b) { return a.second*b.second; });
    cout << dji_index;
}

int main()
{
    example();
    map<string, int> words;
    for (string s; cin >> s; )
        ++words[s];
    for (const auto& p : words)
        cout << p.first << ": " << p.second << '\n';
    return 0;
}
