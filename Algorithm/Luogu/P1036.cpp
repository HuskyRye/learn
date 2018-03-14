#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

bool isprime(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> v;
int sum = 0;

void loop(vector<int>& k, int layer, int begin)
{
    if (layer == k.size()) {
        if (isprime(accumulate(k.begin(), k.end(), 0)))
            ++sum;
        return;
    }
    for (int i = begin; i < v.size(); ++i) {
        k[layer] = v[i];
        loop(k, layer+1, i + 1);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> s(k);
    loop(s, 0, 0);
    cout << sum;
}