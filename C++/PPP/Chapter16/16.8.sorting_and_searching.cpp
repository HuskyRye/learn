#include "std_lib_facilities.h"

struct No_cast {
    bool operator()(const string& x, const string& y) const
    {
        for (int i = 0; i < x.length(); ++i) {
            if (i == y.length())
                return false;
            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if (xx < yy)
                return true;
            if (yy < xx)
                return false;
            if (x.length() == y.length())
                return false;
            return true;
        }
    }
};