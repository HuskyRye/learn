#include <iostream>
#include <vector>
#include <string>
#include <iterator>     // istream_iterator
#include <fstream>
#include <algorithm>    // std::binary_search
#include <random>
#include "26.1.binary_search.h"
using namespace std;

void test1()
{
    vector<int> v { 1, 2, 3, 5, 8, 13, 21 };
    for (int x : {1, 5, 8, 21, -7, 2, 44})
        if (binary_search(v.begin(), v.end(), x) == false)
            cout << x << " failes";
}

// { 编号 查找值 { 序列 } 期望值 }
struct Test {
    string label;
    int val;
    vector<int> seq;
    bool res;
};

ostream& operator<<(ostream& os, const Test& t)
{
    cout << "{ " << t.label << ' ' << t.val << " { ";
    for (auto& x : t.seq)
        cout << x << ' ';
    cout << "} " << t.res << " }\n";
    return os;
}

istream& operator>>(istream& is, Test& t)
{
    string a, b;
    if (is >> a >> t.label >> t.val >> b && (a != "{" || b != "{")) {
        cerr << "ERROR: Invalid test file format\n";
        return is;
    }
    t.seq.clear();
    copy(istream_iterator<int>(is), istream_iterator<int>(), back_inserter(t.seq));
    is.clear();
    
    string c, d;
    int res = 0;
    if (is >> c >> res >> d && (c != "}" || d != "}")) {
        cerr << "ERROR: Invalid test file format\n";
        return is;
    }

    t.res = res;
    return is;
}

int test_all(istream& is)
{
    int error_count = 0;
    for (Test t; is >> t; ) {
        // cout << t;
        bool r = binary_search(t.seq.begin(), t.seq.end(), t.val);
        if (r != t.res) {

            cout << "failure: test " << t.label
                << " binary_search: "
                << t.seq.size() << " elements, v==" << t.val
                << " -> " << t.res << '\n';
            ++error_count;
        }
    }
    return error_count;
}

int rand(int min, int max)
{
    static default_random_engine ran;
    return uniform_int_distribution<>{min, max}(ran);
}

// 向 cout 输出一个测试描述，标签为 lab
// 以 base 为起始值，随意生成 n 个元素的序列
// 元素之间的平均距离是 [0, spread] 之间的均匀分布
void make_test(const string& lab, int n, int base, int spread)
{
    cout << "{ " << lab;
    vector<int> v;
    int elem = base;
    for (int i = 0; i < n; ++i) {
        elem += rand(0, spread);
        v.push_back(elem);
    }
    int val = base + rand(0, elem-base);
    cout << ' ' << val << " { ";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (v[i] == val)
            found = true;
        cout << v[i] << ' ';
    }
    cout << "} " << found << " }\n";
}

void random_test()
{
    int no_of_tests = rand(0, 100);
    for (int i = 0; i < no_of_tests; ++i) {
        string lab = "rand_test_";
        make_test(lab+to_string(i), rand(0, 500), 0, rand(0, 50));
    }
}

int main()
{
    // test1();

    int errors = test_all(ifstream("26.3.2.2.in"));
    cout << "number of errors: " << errors << "\n";

    // random_test();
    int errors2 = test_all(ifstream("26.3.2.3.in"));
    cout << "number of errors: " << errors2 << "\n";
}