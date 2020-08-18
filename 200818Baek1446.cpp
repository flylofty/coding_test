#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int N = 0; // 지름길의 개수
int D = 0; // 고속도로의 길이

vector<pair<int, int>> road[10001];
set<int> v;

void input() {

	cin >> N >> D;
	for (int i = 0; i < N; ++i) {
		int s, e, d;
		cin >> s >> e >> d;

		if (s < D) v.insert(s);
		if (e < D) v.insert(e);
		road[s].push_back(make_pair(e, d)); // 종점, 가중치
	}
	v.insert(D);


	for (set<int>::iterator it = v.begin(); it != v.end(); ++it) {

		if (*it == D) break;

		set<int>::iterator it2 = it;
		it2++;
		road[*it].push_back(make_pair(*it2, *it2 - *it));
	}

}

void findShortestPath() {
	vector<int> distance(D + 1, 2100000000);
	distance[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(distance[0], 0));

	while (!pq.empty()) {
		int node_x = pq.top().second;
		int distance1 = pq.top().first;
		pq.pop();

		for (int i = 0; i < road[node_x].size(); ++i) {
			int node_y = road[node_x][i].first;
			int distance2 = distance1 + road[node_x][i].second;

			if (node_y > D) continue;

			if (distance[node_y] > distance2) {
				distance[node_y] = distance2;
				pq.push(make_pair(distance2, node_y));
			}

		}

	}


	for (set<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << "  " << distance[*it] << endl;
	}

	cout << distance[D] << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	input();
	findShortestPath();

	return 0;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N = 0;
//int D = 0;
//
//int main() {
//
//	cin >> N >> D;
//
//	vector<int> road(D + 1, 0);
//
//	vector<pair<int, pair<int, int>>> shortCut(N + 1);
//	for (int i = 0; i < N; ++i) {
//		cin >> shortCut[i].first >> shortCut[i].second.first >> shortCut[i].second.second;
//	}
//	shortCut.push_back(make_pair(D + 1, make_pair(0,0)));
//	sort(shortCut.begin(), shortCut.end());
//
//	int cur = 0;
//	int chase = 0;
//	while (chase != D) 
//	{
//		cout << chase << " " << cur << "\n";
//		if (shortCut[cur].first == chase) 
//		{
//			if (shortCut[cur].second.first <= D) 
//			{
//				if (road[shortCut[cur].second.first] == 0) {
//					road[shortCut[cur].second.first] = road[chase] + shortCut[cur].second.second;
//				}
//				else {
//					road[shortCut[cur].second.first] = min(road[chase] + shortCut[cur].second.second, road[shortCut[cur].second.first]);
//				}
//			}
//			cur++;
//		}
//		else 
//		{
//			if (road[chase + 1] != 0)
//				road[chase + 1] = min(road[chase + 1], road[chase] + 1);
//			else
//				road[chase + 1] = road[chase] + 1;
//			chase++;
//		}
//	}
//
//	cout << road[D] << "\n";
//
//	return 0;
//}