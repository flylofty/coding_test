#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 진입차수를 이용한 위상정렬
int n = 0;
int m = 0;
vector<int> g[101];
vector<int> inDegree;
char standard;

void input() {

	cin >> n;
	vector<char> temp(n);
	inDegree.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> temp[i];
	}

	standard = temp[0];

	cin >> m;
	for (int i = 0; i < m; ++i) {
		char a, b;
		cin >> a >> b;
		g[a - standard].push_back(b - standard);
		inDegree[b - standard]++;
	}
}

void topologicalSort() {

	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	int cnt = 1;
	vector<char> answer;

	while (!q.empty()) {

		int v1 = q.front();
		answer.push_back(v1 + standard);
		q.pop();

		cnt++;

		for (int i = g[v1].size() - 1; i >= 0; --i) {
			int v2 = g[v1][i];
			inDegree[v2]--;

			if (inDegree[v2] == 0) {
				q.push(v2);
			}
		}

	}

    // 만약 방향그래프가 방향비사이클 그래프이라면 
    // cnt == n + 1 이다!!
	if (n < cnt) {
		for (int i = 0; i < n; ++i) {
			cout << answer[i] << " ";
		}
	}
	else {
		cout << "0";
	}
	cout << "\n";
}

int main() {
	input();
	topologicalSort();
	return 0;
}