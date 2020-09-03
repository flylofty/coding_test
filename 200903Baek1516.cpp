#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
vector<int> g[500];
vector<int> in;
vector<int> time;
vector<int> totalTime;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	in.assign(N, 0);
	time.assign(N, 0);
	totalTime.assign(N, 0);

	for (int i = 0; i < N; ++i) {
		cin >> time[i];
		while (1) {
			int temp;
			cin >> temp;
			if (temp == -1) break;
			g[temp - 1].push_back(i);
			in[i]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int v1 = q.front();
		q.pop();

		for (int i = 0; i < g[v1].size(); ++i) {
			int v2 = g[v1][i];
			//s[v2].insert(v1);
			in[v2]--;

			if (in[v2] == 0) {
				//time[v2] += time[v1];
				q.push(v2);
			}

			int tempTime = totalTime[v1] + time[v1];
			if (totalTime[v2] < tempTime)
				totalTime[v2] = tempTime;

		}
	}

	for (int i = 0; i < N; ++i) {
		cout << time[i] + totalTime[i] << "\n";
	}

	return 0;
}