#include <iostream>
#include <random>
#include <vector>
#include <functional>
using namespace std;

int rand(int min, int max)
{
    default_random_engine ran;
    return uniform_int_distribution<>{min, max}(ran);
}

auto gen = bind(normal_distribution<double>{15, 4.0}, default_random_engine {});   // 均值，方差

void f()
{
    vector<int> hist(2*15);
    for (int i = 0; i < 500; ++i)
        ++hist[int(round(gen()))];
    for (int i = 0; i < hist.size(); ++i) {
        cout << i << '\t';
        for (int j = 0; j < hist[i]; ++j)
            cout << '*';
        cout << '\n';
    }
}

int main()
{
    f();
    return 0;
}