#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// 다익스트라 알고리즘.
vector<pair<int, int>> bus[1001];

int N, M; // 도시의 개수
int s, d; // 버스의 개수

void input() {
	cin >> N;
	cin >> M;
	pair<int, int> p;
	for (int i = 0; i < M; ++i) {
		int index;
		cin >> index >> p.second >> p.first; // first == cost
		bus[index].push_back(p);
	}
	cin >> s >> d; ////starting point // destination
}

void Dijkstra() {
	vector<int> D(N + 1, 987654321);
	D[s] = 0;
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // cost, vertex
	pq.push(make_pair(0, s));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		for (int i = 0; i < bus[x].size(); ++i) {
			int x_y = cost + bus[x][i].first;
			int y = bus[x][i].second;

			if (D[y] > x_y) {
				D[y] = x_y;
				pq.push(make_pair(x_y, y));
			}
		}
	}

	cout << D[d] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	Dijkstra();
	return 0;
}

//#include <iostream>
//#include <vector>
//
//// 자료구조를 아무리 잘 선정해도 실행시 호출되는 함수 및 그밖에 다른 요소로인한
//// 메모리 누적으로 인하여 메모리 초과를 발생할 수 있다.
//using namespace std;
//
//// vector<pair<int, int>> bus[1001];
//int bus[1001][1001]{ 0 };
//bool visit[1001]{ false };
//
//int N, M; // 도시의 개수
//int s, d; // 버스의 개수
//int minimum = 100000;
//
//void input() {
//	cin >> N;
//	cin >> M;
//	for (int i = 0; i < M; ++i) {
//		int index, destination, cost;
//		cin >> index >> destination >> cost;
//		bus[index][destination] = cost;
//	}
//	cin >> s >> d;
//}
//
//void dfs(int start, int cost) {
//
//	visit[start] = true;
//
//	if (start == d) {
//		if (cost < minimum)
//			minimum = cost;
//		return;
//	}
//
//	for (int i = 1; i < 1001; ++i) {
//		if (bus[start][i] == NULL)
//			continue;
//		if (!visit[i])
//			return dfs(i, bus[start][i] + cost);
//	}
//}
//
//int main() {
//	input();
//	dfs(s, 0);
//	cout << minimum << "\n";
//	return 0;
//}