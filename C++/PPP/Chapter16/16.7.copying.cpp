#include "std_lib_facilities.h"
#include <set>

template<typename In, typename Out>
Out copy(In first, In last, Out res)
{
    while (first != last) {
        *res = *first;
        ++res;
        ++first;
    }
    return res;
}

// copy_if
template<typename In, typename Out, typename Pred>
Out copy_if(In first, In last, Out res, Pred pred)
{
    while (first != last) {
        if (pred(*first)) {
            *res = *first;
            ++res;
        }
        ++first;
    }
    return res;
}

void f(const vector<int>& v)
{
    vector<int> v2(v.size());
    ::copy_if(v.begin(), v.end(), v2.begin(), [](double a) { return a > 6; });
}

int main()
{
    string from, to;
    cin >> from >> to;
    
    ifstream is { from };
    ofstream os { to };

    istream_iterator<string> ii { is };
    istream_iterator<string> eos;
    ostream_iterator<string> oo { os, "\n" };

    vector<string> b { ii, eos };
    sort(b.begin(), b.end());
    ::copy(b.begin(), b.end(), oo);

    ostream_iterator<string> co { os, "\n" };
    set<string> c { ii, eos };
    unique_copy(b.begin(), b.end(), oo);
}