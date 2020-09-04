#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int Min = 0;
vector<int> g[11];
vector<bool> visit;
int e;

void dfs(int s, int sum, int cnt) {

	if (cnt != N) {
		for (int i = 1; i <= N; ++i) {
			if (!visit[i] && g[s][i] != 0 && sum + g[s][i] < Min) {
				visit[i] = true;
				dfs(i, sum + g[s][i], cnt + 1);
				visit[i] = false;
			}
		}
	}
	else {
		if (g[s][e] != 0 && Min > sum + g[s][e])
			Min = sum + g[s][e];
	}
}

int main() {

	cin >> N;
	Min = N * 1000000;
	for (int i = 1; i <= N; ++i) {
		g[i].push_back(0);
		for (int j = 1; j <= N; ++j) {
			int c; cin >> c;
			g[i].push_back(c);
		}
	}

	for (int i = 1; i <= N; ++i) {
		visit.clear();
		visit.resize(N + 1, false);
		e = i;
		visit[i] = true;
		dfs(i, 0, 1);
	}

	cout << Min << "\n";

	return 0;
}