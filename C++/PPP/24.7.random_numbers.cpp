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
