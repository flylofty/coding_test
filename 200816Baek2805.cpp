#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<long long> trees;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	trees.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> trees[i];
	}

	int left = 1;
	int right = 1000000000;

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long cut = 0;
		for (int i = 0; i < trees.size(); ++i) {

			if (trees[i] > mid)
				cut += trees[i] - mid;
		}

		if (cut < M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}

	}

	cout << right << "\n";

	return 0;
}