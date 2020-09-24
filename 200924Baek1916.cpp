#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
        
        if (D[x] < cost)
            continue;

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
	input();
	Dijkstra();
	return 0;
}