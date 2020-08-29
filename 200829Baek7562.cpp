#include <iostream>
#include <queue>

typedef struct knight {
	int x, y, cnt;
}kn;

using namespace std;

int N = 0; // 테스트 케이스의 개수
int l = 0;
int dir[8][2]{ {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {2, 1}, {1, 2} };

int bfs(int s_x, int s_y, int e_x, int e_y) {
	queue<kn> q;
	q.push({s_x, s_y, 0});
	vector<vector<bool>> visit(l, vector<bool>(l, false));
	visit[s_x][s_y] = true;

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();

		//cout << cur_x << "  " << cur_y << "\n";

		if (cur_x == e_x && cur_y == e_y) {
			return cnt;
		}

		for (int i = 0; i < 8; ++i) {
			int n_x = cur_x + dir[i][0];
			int n_y = cur_y + dir[i][1];

			if (n_x >= 0 && n_x < l && n_y >= 0 && n_y < l && !visit[n_x][n_y]) {
				q.push({ n_x, n_y, cnt + 1 });
				visit[n_x][n_y] = true;
			}
		}
	}

}

void findAnswer() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> l;
		int s_x, s_y, e_x, e_y;
		cin >> s_x >> s_y;
		cin >> e_x >> e_y;
		cout << bfs(s_x, s_y, e_x, e_y) << "\n";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	findAnswer();
	return 0;
}