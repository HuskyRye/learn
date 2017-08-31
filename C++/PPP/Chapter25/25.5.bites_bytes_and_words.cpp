#include "std_lib_facilities.h"
#include <bitset>

int main()
{
    for (int i; cin >> i; ) {
        cout << showbase << dec << i << " == " << hex << i << " == " << bitset<32>{static_cast<unsigned int>(i)} << '\n';
    }
    return 0;
}