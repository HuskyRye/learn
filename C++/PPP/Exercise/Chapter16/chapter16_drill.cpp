#include "std_lib_facilities.h"
#include <map>
#include <numeric>

// Drill 1.1
struct Item {
    string name;
    int iid;
    double value;
    Item(){}
    Item(string n, int i, double v) :name { n }, iid { i }, value { v } {}
};

istream& operator>>(istream& is, Item& it)
{
    string n;
    int i;
    double v;
    is >> n >> i >> v;
    if (!is)
        return is;
    it = Item { n, i, v };
    return is;
}

ostream& operator<<(ostream& os, const Item& i)
{
    cout << i.name << '\t' << i.iid << '\t' << i.value << '\n';
    return os;
}

class Find_by_name {
    string name;
public:
    Find_by_name(string s) : name { s } {}
    bool operator()(const Item& a) { return a.name == name; }
};

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) : iid { i } {}
    bool operator()(const Item& a) { return a.iid == iid; }
};

void use_vector()
{
    // Drill 1.1
    vector<Item> vi;
    ifstream ifs { "chapter16_drill_in.txt" };
    if (!ifs)
        error("can't open chapter16_drill_in.txt");
    for (Item i; ifs >> i; )
        vi.push_back(i);
    for (auto& x : vi)
        cout << x;
    cout << '\n';

    // Drill 1.2
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.name < b.name; });
    for (auto& x : vi)
        cout << x;
    cout << '\n';

    // Drill 1.3
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.iid < b.iid; });
    for (auto& x : vi)
        cout << x;
    cout << '\n';

    // Drill 1.4
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b) { return a.value < b.value; });
    for (int i = vi.size()-1; i >= 0; --i)
        cout << vi[i];
    cout << '\n';

    // Drill 1.5
    vi.insert(vi.end(), Item { "Horsesh", 99, 12.34 });
    vi.insert(vi.end(), Item { "C S400", 9988, 499.95 });
    for (auto& x : vi)
        cout << x;
    cout << '\n';

    // Drill 1.6
    vi.erase(find_if(vi.begin(), vi.end(), Find_by_name("Beanie")));
    vi.erase(find_if(vi.begin(), vi.end(), Find_by_name("Xbox")));
    for (auto& x : vi)
        cout << x;
    cout << '\n';

    // Drill 1.7
    vi.erase(find_if(vi.begin(), vi.end(), Find_by_iid(14910)));
    vi.erase(find_if(vi.begin(), vi.end(), Find_by_iid(3484)));
    for (auto& x : vi)
        cout << x;
    cout << '\n';
}

void use_list()
{
    // Drill 2.1
    list<Item> li;
    ifstream ifs { "chapter16_drill_in.txt" };
    if (!ifs)
        error("can't open chapter16_drill_in.txt");
    for (Item i; ifs >> i; )
        li.push_back(i);
    for (auto& x : li)
        cout << x;
    cout << '\n';

    // Drill 2.2
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    for (auto& x : li)
        cout << x;
    cout << '\n';
    
    // Drill 2.3
    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    for (auto& x : li)
        cout << x;
    cout << '\n';
    
    // Drill 2.4
    li.sort([](const Item& a, const Item& b) { return a.value < b.value; });
    for (auto p = --li.end(); p != li.begin(); --p)
        cout << *p;
    cout << '\n';
    
    // Drill 2.5
    li.insert(li.end(), Item { "Horsesh", 99, 12.34 });
    li.insert(li.end(), Item { "C S400", 9988, 499.95 });
    for (auto& x : li)
        cout << x;
    cout << '\n';
    
    // Drill 2.6
    li.erase(find_if(li.begin(), li.end(), Find_by_name("Beanie")));
    li.erase(find_if(li.begin(), li.end(), Find_by_name("Xbox")));
    for (auto& x : li)
        cout << x;
    cout << '\n';
    
    // Drill 2.7
    li.erase(find_if(li.begin(), li.end(), Find_by_iid(14910)));
    li.erase(find_if(li.begin(), li.end(), Find_by_iid(3484)));
    for (auto& x : li)
        cout << x;
    cout << '\n';
}

// Drill 3.2
template<typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p)
{
    os << setw(12) << left << p.first << '\t' << p.second << '\n';
    return os;
}

// Drill 3.5
istream& operator>>(istream& is, map<string, int>& msi)
{
    string s;
    int n;
    is >> s >> n;
    if (!is)
        return is;
    msi[s] = n;
    return is;
}

void use_map()
{
    // Drill 3.1
    map<string, int> msi;

    // Drill 3.2
    msi["lecture"] = 21;
    msi["university"] = 35;
    msi["education"] = 15;
    msi["school"] = 99;
    msi["kindergarten"] = 105;
    msi["river"] = 5;
    msi["city"] = 10;
    msi["capital"] = 70;
    msi["software"] = 88;
    msi["hardware"] = 43;

    // Drill 3.3
    for (auto& x : msi)
        cout << x;
    cout << '\n';

    // Drill 3.4
    for (auto p = msi.begin(); p != msi.end(); )
        p = msi.erase(p);
    cout << "Size of map after deleting: " << msi.size() << '\n';

    // Drill 3.6
    while (cin) {
        cin >> msi;
    }
    // Drill 3.7
    for (auto& x : msi)
        cout << x;
    cout << '\n';

    // Drill 3.8
    int sum = accumulate(msi.begin(), msi.end(), 0, [](int v, const pair<string, int>& b) { return v+b.second; });
    cout << "the sum of map<string, int> mis: " << sum << '\n';

    // Drill 3.9
    map<int, string> mis;

    // Drill 3.10
    for (auto& x : msi)
        mis[x.second] = x.first;

    // Drill 3.11
    for (auto& x : mis)
        cout << x;
}

ostream& operator<<(ostream& os, vector<double> vd)
{
    cout << "{ ";
    for (int i = 0; i < vd.size(); ++i)
        os << vd[i] << (i == vd.size()-1 ? " " : ", ");
    cout << "}\n";
    return os;
}

template<typename T>
class Less_than {
    T val;
public:
    Less_than<T>(T v) : val { v } {}
    bool operator()(T v) const { return v<val; }
};

void more_vector()
{
    // Drill 1
    vector<double> vd;
    ifstream ifs { "chapter16_drill_in2.txt" };
    if (!ifs)
        error("can't open chapter16_drill_in2.txt");
    for (double v; ifs >> v; )
        vd.push_back(v);
    
    // Drill 2
    cout << vd;

    // Drill 3
    vector<int> vi(vd.size());
    copy(vd.begin(), vd.end(), vi.begin());

    // Drill 4
    for (int i = 0; i < vi.size(); ++i)
        cout << '(' << vd[i] << ", " << vi[i] << ")\n";

    // Drill 5
    double sum_of_vd = accumulate(vd.begin(), vd.end(), 0.0);
    cout << "sum of vd: " << sum_of_vd << '\n';

    // Drill 6
    int sum_of_vi = accumulate(vi.begin(), vi.end(), 0);
    cout << "sum_of_vd - sum_of_vi: " << sum_of_vd - sum_of_vi << '\n';

    // Drill 7
    reverse(vd.begin(), vd.end());
    cout << vd;

    // Drill 8
    double average_of_vd = sum_of_vd / vd.size();
    cout << "average of vd: " << average_of_vd << '\n';

    // Dill 9
    vector<double> vd2(count_if(vd.begin(), vd.end(), Less_than<double>(average_of_vd)));
    copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than<double>(average_of_vd));
    cout << vd2;

    // Drill 10
    sort(vd2.begin(), vd2.end());
    cout << vd2;
}

int main()
{
    // use_vector();
    // use_list();
    // use_map();
    more_vector();
    return 0;
}