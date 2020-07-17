#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N;
int map[101][101]{ 0 };
int h_max = 0;
int h_min = 100;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void BFS(bool v[101][101], int height, int x, int y) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];

			if ((next_x >= 1 && next_x <= N) && (next_y >= 1 && next_y <= N) && !v[next_x][next_y] && map[next_x][next_y] > height) {
				q.push(pair<int, int>(next_x, next_y));
				v[next_x][next_y] = true;
			}

		}
	}
}

void findAnswer() {

	int m = 1;
	for (int i = h_min; i <= h_max - 1; ++i) {

		int cnt = 0;
		bool isVisited[101][101]{ false };
		for (int j = 0; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				if (map[j][k] > i && !isVisited[j][k]) {
					cnt++;
					BFS(isVisited, i, j ,k);
				}
			}
		}

		if (cnt > m)
			m = cnt;
	}
	cout << m << "\n";
}

void input() {
	
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &map[i][j]);

			if (h_max < map[i][j])
				h_max = map[i][j];

			if (h_min > map[i][j])
				h_min = map[i][j];

		}
	}
}

int main() {

	input();
	findAnswer();

	return 0;
}