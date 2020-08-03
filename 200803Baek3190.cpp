#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int d = 0;
int dir[4][2]{ {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // -->,   <--,  ↑  ,  ↓

int N = 0;
int map[101][101]{ 0 };
bool isBody[101][101]{ false };

int K = 0; // number of Apple
deque<pair<int, int>> snake; // 꼬리

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	pair<int, int> temp(1, 1);
	snake.push_back(temp);
	isBody[1][1] = true;

	cin >> N;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}

	int n_t = 0;
	cin >> n_t;
	queue<pair<int, char>> turn;
	for (int i = 0; i < n_t; ++i) {
		pair<int, char> p;
		cin >> p.first >> p.second;
		turn.push(p);
	}

	int time = 0;
	while (1) {

		if (!turn.empty() && turn.front().first == time) {
			if (turn.front().second == 'L') { // 왼쪽 전환
				if (d == 0) d = 2;
				else if (d == 1) d = 3;
				else if (d == 2) d = 1;
				else if (d == 3) d = 0;
			}
			else { // 오른쪽 전환
				if (d == 0) d = 3;
				else if (d == 1) d = 2;
				else if (d == 2) d = 0;
				else if (d == 3) d = 1;
			}
			turn.pop();
		}

		int next_x = snake.front().first + dir[d][0];
		int next_y = snake.front().second + dir[d][1];
		time++;

		// 머리가 맵을 벗어났는지 확인.
		if (!(next_x > 0 && next_x <= N && next_y > 0 && next_y <= N)) break;
		// 몸이랑 붙딛쳤는지 확인
		if (isBody[next_x][next_y]) break;

		pair<int, int> temp(next_x, next_y);
		snake.push_front(temp);
		isBody[next_x][next_y] = true;

		// 사과가 놓인 곳이 아니라면...
		if (!map[next_x][next_y]) {
			int tail_x = (*snake.rbegin()).first;
			int tail_y = (*snake.rbegin()).second;
			isBody[tail_x][tail_y] = false;
			snake.pop_back();
		} 
		else {
			map[next_x][next_y] = 0;
		}

	}

	cout << time << "\n";

	return 0;
}