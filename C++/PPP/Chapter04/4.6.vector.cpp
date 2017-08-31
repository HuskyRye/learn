#include "std_lib_facilities.h"

int main1()
{
	vector<int> v = { 5, 7, 9, 4, 6, 8 };
	vector<string> philosopher = { "Kant", "Plato", "Hume", "Kierkegaard" };

	vector<int> vi(6);
	vector<string> vs(4);
	return 0;
}

int main2()
{
	vector<int> v = { 5, 7, 9, 4, 6, 8 };
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << '\n';

	for (int x : v)
		cout << x << '\n';

	return 0;
}

// 把温度值读入一个 vector，并计算温度的均值和中值
int main3()
{
	vector<double> temps;
	for (double temp; cin >> temp;) {
		temps.push_back(temp);
	}

	double sum = 0;
 	for (int x : temps)
		sum += x;
	cout << "Average temperature: " << sum/temps.size() << '\n';

	sort(temps);
	cout << "Median temperature: " << temps[temps.size()/2] << '\n';
	return 0;
}

// 简单字典程序：建立排序单词的列表
int main4()
{
	vector<string> words;
	for (string temp; cin >> temp; ) {
		words.push_back(temp);
	}
	cout << "Number of words: " << words.size() << '\n';

	sort(words);

	for (int i = 0; i < words.size(); ++i) {
		if (i == 0 || words[i-1] != words[i])
			cout << words[i] << '\n';
	}
	keep_window_open();
	return 0;
}