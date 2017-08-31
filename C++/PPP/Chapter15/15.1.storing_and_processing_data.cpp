#include "std_lib_facilities.h"

double* get_from_jack(int* count);  // Jack 将 double 值存入一个数组并将元素个数藉由 *count 返回
vector<double>* get_from_jill();    // Jill 填充 vector

double* high(double* first, double* last)
{
    double h = -1;
    double* high;
    for (double* p = first; p != last; ++p)
        if (h < *p) {
            high = p;
            h = *p;
        }
    return high;
}

int main()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_date = get_from_jill();

    /*
    double h = -1;
    double* jack_high;
    double* jill_high;
    for (int i = 0; i < jack_count; ++i) {
        if (h < jack_data[i]) {
            jack_high = &jack_data[i];      // 保存最大元素地址
            h = jack_data[i];               // 更新最大元素
        }
    }
    h = -1;
    vector<double>& v = *jill_date;
    for (int i = 0; i < v.size(); ++i) {
        if (h < v[i]) {
            jill_high = &v[i];   // 保存最大元素地址
            h = v[i];            // 更新最大元素
        }
    }
    */

    double* jack_high = high(jack_data, jack_data+jack_count);
    vector<double>& v = *jill_date;
    double* jill_high = high(&v[0], &v[0]+v.size());

    double* middle = &v[0]+v.size()/2;
    double* high1 = high(&v[0], middle);
    double* high2 = high(middle, &v[0]+v.size());

    delete[] jack_data;
    delete jill_date;
}