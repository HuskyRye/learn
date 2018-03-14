/*
	Author: 刘臣轩
	Date: 2017.10.27
	Source: NOIP 2007
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;

	string ans;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '-' && ((isdigit(s[i - 1]) && isdigit(s[i + 1])) || (isalpha(s[i - 1]) && isalpha(s[i + 1]))) && s[i - 1] < s[i + 1]) {
			string temp;
			char begin = s[i - 1] + 1;
			int n = s[i + 1] - s[i - 1] - 1;
			if (p1 == 3)
				for (int i = 0; i < p2*n; ++i)
					temp += '*';
			else {
				if (p1 == 2)
					begin = toupper(begin);
				for (char i = begin; i < begin + n; ++i)
					for (int j = 0; j < p2; ++j)
						temp += i;
			}
			if (p3 == 1)
				ans += temp;
			else
				ans += string(temp.rbegin(), temp.rend());
		}
		else
			ans += s[i];
	}
	
	cout << ans << endl;

	return 0;
}