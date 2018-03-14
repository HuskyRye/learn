#include <iostream>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    int i = 1;
    int j = 1;
    while (n > 1) {
        ++j;
        // cout << i << '\t' << j << '\n';
        --n;
        while (j > 1 && n > 1) {
            ++i;
            --j;
            // cout << i << '\t' << j << '\n';
            --n;
        }
        ++i;
        // cout << i << '\t' << j << '\n';
        --n;
        while (i > 1 && n > 1) {
            --i;
            ++j;
            // cout << i << '\t' << j << '\n';
            --n;
        }
    }
    cout << i << '/' << j << '\n';
}