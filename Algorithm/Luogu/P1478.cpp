#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    int h = a + b;
    vector<pair<int, int>>apple;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        apple.push_back(make_pair(a, b));
    }
    sort(apple.begin(), apple.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second; });
    int sum = 0;
    for (auto p = apple.begin(); p != apple.end(); ++p) {
        if (p->first <= h && p->second <= s) {
            s -= p->second;
            ++sum;
        }
    }
    cout << sum << '\n';
}