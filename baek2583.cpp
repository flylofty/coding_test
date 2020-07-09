#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M = 0, N = 0, K = 0;
bool isVisited[100][100]{ false };
vector<vector<int>> paper(100, vector<int>(100, 1));
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void drawPaper(int &a, int &b, int &c, int &d) {

	for (int i = M - d; i < M - b; ++i) {
		for (int j = a; j < c; ++j) {
			isVisited[i][j] = true;
			paper[i][j] = 0;
		}
	}
}

bool isIn(int &x, int &y) {
	if (x >= 0 && x < M && y >= 0 && y < N) {
		return true;
	}
	else {
		return false;
	}
}

int BFS(int x, int y) {

	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	isVisited[x][y] = true;
	int area = 0;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		area++;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];

			if (isIn(next_x, next_y) && isVisited[next_x][next_y] == false) {
				isVisited[next_x][next_y] = true;
				q.push(pair<int, int>(next_x, next_y));
			}
		}

	}

	return area;
}

void findResult() {

	priority_queue<int, vector<int>, greater<int>> area;
	int cnt = 0;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if(isVisited[i][j] == false) {
				area.push(BFS(i, j));
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	while (!area.empty()) {
		cout << area.top() << " ";
		area.pop();
	}

}

int main() {


	cin >> M >> N >> K;

	for (int i = 0; i < K; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		drawPaper(a, b, c, d);
	}

	findResult();

	return 0;
}