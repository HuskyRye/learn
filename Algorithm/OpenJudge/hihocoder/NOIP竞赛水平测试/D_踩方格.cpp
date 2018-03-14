/*
	Date: 2018.3.13
	Author: 刘臣轩
*/

#include <iostream>

using namespace std;

/*
enum direction {
	NORTH,
	EAST,
};

int run(int prev, int n)
{
    if (n == 0)
        return 1;
    int res = 0;
    if (prev == NORTH) {
        res += run(NORTH, n - 1);
        res += 2 * run(EAST, n - 1);
    } else {
        res += run(NORTH, n - 1);
        res += run(EAST, n - 1);
    }
    return res;
}
*/

int result[] = { 0, 3, 7, 17, 41, 99, 239, 577, 1393, 3363, 8119, 19601, 47321, 114243, 275807, 665857, 1607521, 3880899, 9369319, 22619537, 54608393 };

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << result[n] << endl;
    return 0;
}
