#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0;
	cin >> N;
	vector<pair<int, int>> candidate;
	for (int i = 0; i < N; ++i) {
		int D, C; cin >> D >> C;
		candidate.push_back(make_pair(D, C));
	}

	int cnt = 0;
	for (int i = 0; i < candidate.size(); ++i) {
		bool condo = false;
		for (int j = 0; j < candidate.size(); ++j) {
			if (i == j) continue;
			if (candidate[i].first > candidate[j].first) {
				if (candidate[i].second >= candidate[j].second) {
					condo = true;
					break;
				}
			}
			else if (candidate[i].second > candidate[j].second) {
				if (candidate[i].first >= candidate[j].first) {
					condo = true;
					break;
				}
			}
		}
		if (!condo)
			cnt++;
	}
	cout << cnt << "\n";
	return 0;
}