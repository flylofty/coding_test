#include <iostream>
#include <queue>

//bfs를 이용함.

using namespace std;

int map[101][101];
int visited[101];
int n, m, cnt = 0;

void bfs(int start) {

	queue<int> q;
	visited[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 1; i <= n; ++i) {
			if (!visited[i] && map[node][i] == 1) {
				q.push(i);
				visited[i] = 1;
				cnt++;
			}
		}
	}

}

int main() {

	cin >> n;
	cin >> m;

	{
		int u, v;
		for (int i = 1; i <= m; ++i) {
			cin >> u >> v;
			map[u][v] = map[v][u] = 1;
		}
	}

	bfs(1);
	cout << cnt << endl;

	return 0;
}

////부르트포스로 작성한 코드 망....ㅎㅎㅎ
//벡터 필요없음.
//#include <vector>
//int main() {
//
//	int num = 0;
//	cin >> num;
//
//	vector<bool> isInfected(num + 1, false);
//	isInfected[1] = true;
//
//	int cnt = 0;
//
//	int connNum = 0;
//	cin >> connNum;
//
//	vector<vector<int>> conns(connNum, vector<int>(2, 0));
//
//	for (int i = 0; i < connNum; ++i) {
//		cin >> conns[i][0] >> conns[i][1];
//
//		if (isInfected[conns[i][1]])
//			continue;
//
//		if (isInfected[conns[i][0]]) {
//			isInfected[conns[i][1]] = true;
//			cnt++;
//			//cout << conns[i][1] << " 감염됨" << endl;
//		}
//	}
//
//	cout << cnt << endl;
//
//	//https://www.acmicpc.net/problem/2606
//  //http://from20180718.blogspot.com/2018/09/c-2606-dfs-bfs.html
//	return 0;
//}