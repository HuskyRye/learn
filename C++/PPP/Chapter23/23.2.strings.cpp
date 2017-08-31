#include "std_lib_facilities.h"

template<typename T> string to_string(const T& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

struct bad_from_string : std::bad_cast {
    const char* what() const override
    {
        return "bad cast from string";
    }
};

template<typename T> T from_string(const string& s)
{
    istringstream is { s };
    T t;
    if (!(is >> t))
        throw bad_from_string { };
    return t;
}

template<typename Target, typename Source>
Target to(Source arg)
{
    stringstream interpreter;
    Target result;

    if (!(interpreter << arg) || !(interpreter >> result) || !(interpreter >> std::ws).eof())
        throw runtime_error { "to<>() failes" };
    return result;
}

int main()
{
    int a = to<int, string>("123");
    cout << a << '\n';
    return 0;
}