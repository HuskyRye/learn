/*
    3.编写一个模板类 Pair ，该类能够存储任何类型的值对。实现一个符号表
*/

#include "std_lib_facilities.h"

template<class T, class U> struct Pair {
    Pair(T vt, U vu) :val1 { vt }, val2 { vu } { }
    T val1;
    U val2;
};

class Variable {
public:
    double get_value(string s);
    void set_value(string s, double d);
    bool is_declared(string var);
    double define_name(string var, double val);
    void print();
private:
    vector<Pair<string, double>> var_table;
};

double Variable::get_value(string s)
{
    for (int i = 0; i < var_table.size(); ++i)
        if (var_table[i].val1 == s)
            return var_table[i].val2;
    error("get: undefined variable ", s);
}

void Variable::set_value(string s, double d)
{
    for (auto& x : var_table) {
        if (x.val1 == s) {
            x.val2 = d;
            return;
        }
    }
    error("set: undefined variable ", s);
}

bool Variable::is_declared(string var)
{
    for (const auto& x : var_table)
        if (x.val1 == var)
            return true;
    return false;
}

double Variable::define_name(string var, double val)
{
    if (is_declared(var))
        error(var, " declared twice");
    var_table.push_back(Pair<string, double>{var, val});
    return val;
}

void Variable::print()
{
    for (int i = 0; i < var_table.size(); ++i)
        cout << var_table[i].val1 << ": " << var_table[i].val2 << '\n';
}

int main()
try {
    Variable st;
    st.define_name("Pi", 3.14);
    st.define_name("e", 2.72);
    st.print();
    cout << "Pi is " << st.get_value("Pi") << "\n";
    cout << (st.is_declared("Pi") ? "Pi is declared\n" : "Pi is not declared\n");
    cout << (st.is_declared("nd") ? "nd is declared\n" : "nd is not declared\n");
    st.set_value("Pi", 4.14);
    cout << "Pi is now " << st.get_value("Pi") << "\n";

    // provoke errors
    // cout << st.get_value("nd") << "\n";
    // st.set_value("nd",99);
    // st.define_name("Pi",99);
}
catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}
