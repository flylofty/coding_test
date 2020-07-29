#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<pair<int, pair<int, int>>> nodes;
int con[1001][1001]{0};
vector<bool> isVisited;

void input() {

	cin.tie(0);
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i) {
		int n1, n2, cost;
		pair<int, pair<int, int>> temp;
		cin >> temp.second.first >> temp.second.second >> temp.first;
		nodes.push_back(temp);
	}
	isVisited.resize(N + 1, false);
	sort(nodes.begin(), nodes.end());
}

bool isConnected(int s, int e) {

	isVisited[s] = true;

	if (s == e) return true;

	for (int i = 1; i <= N; ++i) {
		if (con[s][i] && !isVisited[i]) {
			bool temp = isConnected(i, e);
			if (temp) return true;
		}
	}

	return false;
}

void turnFalse() {
	for (int i = 1; i <= N; ++i)
		isVisited[i] = false;
}

void findAnswer() {
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < nodes.size(); ++i) {

		int s = nodes[i].second.first;
		int e = nodes[i].second.second;
		int v = nodes[i].first;
		turnFalse();

		if (!isConnected(s, e)) {
			sum += v;
			cnt++;
			con[s][e] = con[e][s] = 1;
		}

		if (cnt == N - 1) break;

	}
	cout << sum << "\n";
}

int main() {

	input();
	findAnswer();

	return 0;
}