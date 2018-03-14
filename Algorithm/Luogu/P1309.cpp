/*
	Author: 刘臣轩
	Date: 2017.11.5
	Source: NOIP 2011 提高
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

struct Player
{
	int id;
	int weight;
	int score;
	bool operator>(const Player& b) const;
}player[200010], winner[100005], looser[100005];

bool Player::operator>(const Player& b) const{
	return score != b.score ? score > b.score : id < b.id;
}

int main() {
	ios::sync_with_stdio(false);
	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 1; i <= 2 * N; ++i) {
		cin >> player[i].score;
		player[i].id = i;
	}
	for (int i = 1; i <= 2 * N; ++i)
		cin >> player[i].weight;

	stable_sort(player + 1, player + 2 * N + 1, greater<Player>());
	for (int i = 1; i <= R; ++i) {
		int win = 0, lose = 0;
		for (int i = 1; i <= N; ++i)
			if (player[2 * i - 1].weight > player[2 * i].weight) {
				++player[2 * i - 1].score;
				winner[++win] = player[2 * i - 1];
				looser[++lose] = player[2 * i];
			}
			else {
				++player[2 * i].score;
				winner[++win] = player[2 * i];
				looser[++lose] = player[2 * i - 1];
			}
			merge(winner + 1, winner + 1 + N, looser + 1, looser + 1 + N, player + 1, greater<Player>());
	}
	cout << player[Q].id << endl;
	return 0;
}