#include <iostream>
#include <stack>

using namespace std;

int map[101][101];
int visited[101]{0};
int n, m;
int cnt = 0;

void DFS(int start) {

	stack<int> s;
	visited[start] = 1;
	s.push(start);

	while (!s.empty()) {

		for (int i = 1; i <= n; ++i) {

			if (!visited[i] && map[s.top()][i] == 1) {
				visited[i] = 1;
				cnt++;
				s.push(i);
				break;
			}

			if ( i == n ) 
				s.pop();
		}
	}

	cout << cnt << endl;
}

int main() {

	cin >> n;
	cin >> m;

	{
		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			map[u][v] = map[v][u] = 1;
		}
	}

	DFS(1);
	return 0;
}