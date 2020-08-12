#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> vote(N + 1, 0);
	vector<pair<int, int>> e; // event

	for (int i = 0; i < N; ++i) {
		int cost; cin >> cost;
		e.push_back(make_pair(cost, i + 1));
	}
	sort(e.begin(), e.end());

	int max = 0;
	int max_index;
	for (int i = 0; i < M; ++i) {
		int cost; cin >> cost;
		int index = 0;
		int min = 1000;
		while (e[index].first <= cost) {
			if (e[index].second < min)
				min = e[index].second;
			index++;
		}
		vote[min]++;

		if (vote[min] > max) {
			max = vote[min];
			max_index = min;
		}
	}

	cout << max_index << "\n";

	return 0;
}