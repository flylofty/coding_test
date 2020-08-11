#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> paper;
// vector<vector<bool>> visit;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int BFS(int x, int y) {
	pair<int, int> p(x, y);
	queue<pair<int, int>> q;
	paper[x][y] = -1;
	q.push(p);

	int size = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		// visit[a][b] = true;
		size++;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int n_a = a + dir[i][0];
			int n_b = b + dir[i][1];

			if (n_a >= 0 && n_a < n && n_b >= 0 && n_b < m /*&& !visit[n_a][n_b]*/ && paper[n_a][n_b] == 1) {
				// visit[n_a][n_b] = true;
				pair<int, int> p(n_a, n_b);
				paper[n_a][n_b] = -1;
				q.push(p);
			}
		}

	}

	return size;
}

void findAnswer() {

	cin >> n >> m;
	paper.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> paper[i][j];
		}
	}
	// visit.resize(n, vector<bool>(m, false));

	int n_p = 0;
	int max_size = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (paper[i][j] == 1 /*&& !visit[i][j]*/) {
				int size = BFS(i, j);
				n_p++;
				if (size > max_size)
					max_size = size;
			}
		}
	}
	cout << n_p << "\n";
	cout << max_size << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	findAnswer();

	return 0;
}