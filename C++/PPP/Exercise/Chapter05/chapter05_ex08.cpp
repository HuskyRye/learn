/*
    8.读取并存储一列整数，计算前 N 个整数的和
    10.使用 double 而不是 int，存储并输出 N-1 个相邻元素的差
*/

#include "std_lib_facilities.h"
#include <numeric>

int main()
try {
    vector<double> v;
    cout << "Please enter the number of values you want to sum:\n";
    int n;
    cin >> n;
    if (n < 1)
        throw runtime_error("You have to sum at least one value!");
    cout << "Please enter some numbers (press '|' to stop)\n";
    double val;
    while (cin >> val)
        v.push_back(val);
    if (n > v.size())
        throw runtime_error("You wanted to sum more values than you entered");
    cout << "The sum of the first " << n << " numbers ( ";
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
        sum += v[i];
    }
    cout << ") is " << sum << '\n';
    vector<double> d(v.size());
    adjacent_difference(v.begin(), v.end(), d.begin());
    for (int i = 1; i < n; ++i)
        cout << d[i] << ' ';
    cout << '\n';
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown exception!\n";
    return 2;
}