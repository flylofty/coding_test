#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int field[50][50]{0};
int M = 0, N = 0, K = 0; // 가로(열), 세로(행), 배추가 심어진 위치의 개수
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector< pair<int, int> > v;

bool isIn(int x, int y) {

	if ((x >= 0 && x < N) && (y >= 0 && y < M)) {
		return true;
	}
	else {
		return false;
	}
}

void BFS(int x, int y) { //행, 렬 인덱스가 들어옴.

	int cur_x = x, cur_y = y;
	bool visited[50][50]{ false };
	queue <pair<int, int>> q;
	q.push(pair<int, int>(cur_x, cur_y));
	visited[x][y] = true;

	while (!q.empty()) {

		cur_x = q.front().first;
		cur_y = q.front().second;
		field[cur_x][cur_y] = 0;
		q.pop();

		for (int i = 0; i < 4; ++i) {

			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];

			if (isIn(next_x, next_y) && field[next_x][next_y] == 1 && visited[next_x][next_y] == false) {
				visited[next_x][next_y] = true;
				q.push(pair<int, int>(next_x, next_y));
			}
		}
	}
}

void findResult() {

	int cnt = 0;
	for (int i = 0; i < v.size(); ++i) {

		int x = v[i].first;
		int y = v[i].second;
		if (field[x][y] == 1) {
			cnt++;
			BFS(x, y);
		}
	}
	v.clear();
	cout << cnt << endl;
}

int main() {

	int T = 0;
	cin >> T; //테스트 케이스의 수

	while (T--) {

		cin >> M >> N >> K; //가로길이, 세로길이, 배추가 심어져 있는 위치의 개수.
		
		int X = 0, Y = 0;
		for (int i = 0; i < K; ++i) {
			cin >> X >> Y;
			field[Y][X] = 1;
			v.push_back(pair<int, int>(Y, X));
		}
		findResult();
	}

	return 0;
}