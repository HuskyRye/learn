#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>   // max_element
using namespace std;

void answer(vector<int> v, int a);

int main()
{
    int m, n, k, l, d;      // M行 N列 K横 L竖 D对
    cin >> m >> n >> k >> l >> d;
    vector<int> vertical(n, 0);      // 竖
    vector<int> horizontal(m, 0);    // 横
    for (int i = 0; i < d; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;        
        // 这里只有两种可能，要么水平，要么竖直，将能分割他们的线数值+1
        if (x1 == x2)
            vertical[(y1 < y2 ? y1 : y2)]++;
        else
            horizontal[(x1 < x2 ? x1 : x2)]++;
    }
    answer(horizontal, k);
    answer(vertical, l);
    return 0; 
}

// 在 v 中寻找 a 个最大元素，排序后打印输出
void answer(vector<int> v, int a)
{
    vector<int> ans;
    for (int i = a; i > 0; --i) {
        // 找到最大数值，放入答案数组，然后将最大数值设为0
        auto p = max_element(v.begin(), v.end());
        ans.push_back(p-v.begin());
        *p = 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < a; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}
