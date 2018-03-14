/*
	Date: 2018.3.13
	Author: 刘臣轩
*/

#include <iostream>
#include <string>

using namespace std;

#define Tie 0
#define P1 1
#define P2 2

int rps[3][3] = {
    { Tie, P1, P2 },
    { P2, Tie, P1 },
    { P1, P2, Tie }
};

int h2i(string hand)
{
    if (hand == "Rock")
        return 0;
    else if (hand == "Scissors")
        return 1;
    else
        return 2;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string player1;
    string player2;
    int p1;
    int p2;
    for (int i = 0; i < n; ++i) {
        cin >> player1;
        cin >> player2;
        p1 = h2i(player1);
        p2 = h2i(player2);
        switch (rps[p1][p2]) {
        case 0:
            cout << "Tie\n";
            break;
        case 1:
            cout << "Player1\n";
            break;
        case 2:
            cout << "Player2\n";
            break;
        }
    }
    return 0;
}
