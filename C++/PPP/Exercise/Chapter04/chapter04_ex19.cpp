/*
	19.输入一组名字和数值对，例如 Joe 17 和 Barbara 22，最后按照 (name, score) 对的形式输出所有数据
	20.当输入一个名字，输入相应成绩或 "name not found"
	21.当输入一个整数，输入相应名字或 "score not found"
*/

#include "std_lib_facilities.h"

int main()
{
    vector<string> names;
    vector<int> scores;
    string name;
    int score;
    while(cin >> name >> score) {
        names.push_back(name);
        scores.push_back(score);
    }
    cin.clear();
    for (int i = 0; i < names.size(); ++i)
        cout << '(' << names[i] << ", " << scores[i] << ")\n";

    while (cin >> name) {
        if (isdigit(name[0])) {
            score = stoi(name);
            auto p = find(scores.begin(), scores.end(), score);
            if (p != scores.end()) {
                cout << names[p-scores.begin()] << '\n';
            }
            else
                cout << "score not found\n";
        }
        else {
            auto p = find(names.begin(), names.end(), name);
            if (p != names.end()) {
                cout << scores[p-names.begin()] << '\n';
            }
            else
                cout << "name not found\n";
        }

    }
}