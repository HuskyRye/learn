/*
    12.公牛和母牛
    13.生成随机数
*/

#include "std_lib_facilities.h"

int main()
{
    int seed;
    cout << "Enter seed for random numbers: ";
    cin >> seed;
    srand(seed);
    vector<int> answer { rand()%10, rand()%10, rand()%10, rand()%10 };
    string guess;
    while (cin >> guess) {
        int bulls = 0;      // 公牛
        int cows = 0;       // 母牛
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int temp = (guess[i]-'0');
                if (answer[j] == temp) {
                    if (i == j) {
                        ++bulls;
                        continue;
                    }
                    else {
                        ++cows;
                        continue;
                    }
                }
            }
        }
        if (bulls == 4)
            break;
        else {
            cout << "bulls: " << bulls << '\n';
            cout << "cows : " << cows << '\n';
        }
    }
    cout << "You win!\n";
    return 0;
}