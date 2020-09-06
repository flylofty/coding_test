#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N = 0;
	int K = 0;
	cin >> N >> K;

	int sum = 0;

	vector<int> v(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (i < K)
		{
			sum += v[i];
		}
	}

	int Max = sum;

	for (int i = K; i < N; ++i) {
		sum += v[i] - v[i - K];

		if (sum > Max)
			Max = sum;
	}

	cout << Max << "\n";
	return 0;
}