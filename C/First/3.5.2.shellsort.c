#include <stdio.h>
#include <stdlib.h>

void shellsort(int v[], int n);

int main()
{

    system("pause");
    return 0;
}

/* shellsort函数：数据结构再看看吧 */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; ++i)
        {
            for (j = i - gap; j>=0 && v[j] > v[j + gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

