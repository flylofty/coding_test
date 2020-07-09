#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int N = 0;
vector<vector<int>> map(25, vector<int>(25, 0));
vector<vector<bool>> isVisited(25, vector<bool>(25, true));
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void input() {
	string s;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < N; ++j) {

			map[i][j] = static_cast<int>(s[j] - '0');

			if (map[i][j])
				isVisited[i][j] = false;
		}
	}
}

bool isIn(int &x, int &y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return true;
	else return false;
}

int BFS(int x, int y) {

	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	int home = 0;
	isVisited[x][y] = true;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		home++;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];

			if (isIn(next_x, next_y) && isVisited[next_x][next_y] == false) {
				q.push(pair<int, int>(next_x, next_y));
				isVisited[next_x][next_y] = true;
			}
		}
	}

	return home;
}

void findResult() {
	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (isVisited[i][j] == false) {
				v.push_back(BFS(i, j));
				cnt++;
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << cnt << endl;
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << "\n";
	}
}

int main() {

	input();
	findResult();
	return 0;
}