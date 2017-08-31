#include <chrono>
#include <iostream>
#include <ctime>
using namespace std;
using namespace std::chrono;

int main()
{
    int n = 10000000;
    auto t1 = chrono::system_clock::now();

    for (int i = 0; i < n; ++i){ /* do something */ }
    auto t2 = chrono::system_clock::now();
    cout << "do_something() " << n << " times took "
        << duration_cast<milliseconds>(t2-t1).count() << "milliseconds\n";

}