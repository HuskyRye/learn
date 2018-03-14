#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> v(m, -1);
    int index = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int word;
        cin >> word;
        if (find(v.begin(), v.end(), word) != v.end()) {
            continue;
        }
        else {
            v[index++] = word;
            ++count;
            if (index == m)
                index = 0;
        }
    }
    cout << count << '\n';
}