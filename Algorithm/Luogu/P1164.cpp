/*
    Author: 刘臣轩
    Date: 2017.11.9
*/

#include <iostream>
using namespace std;

int f[105][10005];
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
    	int v;
    	cin >> v;
    	for (int j = 0; j <= m; ++j) {
    		if (j >= v)
    			f[i][j] = f[i-1][j] + f[i-1][j-v];
    		else
    			f[i][j] = f[i-1][j];
		}	
	}
	cout << f[n][m] << endl;
    return 0;
}
