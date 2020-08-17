#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	long long K, N;
	cin >> K >> N; // 가지고 있는 랜선의 수, 필요한 랜선의 수

	long long left = 1;
	long long right = 0;

	vector<long long> wire(K);
	for (int i = 0; i < K; ++i) {
		cin >> wire[i];

		if (right < wire[i])
			right = wire[i];
	}

	while (left <= right) {
		long long mid = (left + right) / 2; // 자르고자하는 길이

		long long cnt = 0;
		for (int i = 0; i < K; ++i) {
			cnt += wire[i] / mid;
		}

		if (cnt < N) {
			right = mid - 1;
		}
		else {// cnt >= N
			left = mid + 1;
		}
	}

	cout << right << "\n";

	return 0;
}