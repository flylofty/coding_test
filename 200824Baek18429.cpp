#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N = 0;
	int K = 0;
	cin >> N >> K;
	vector<int> kit(N);
	vector<int> num(N);
	for (int i = 0; i < N; ++i) {
		cin >> kit[i];
		num[i] = i;
	}
	int cnt = 0;
	do {
		int i; 
		int weight = 500;
		for (i = 0; i < N; ++i) {
			int index = num[i];
			weight += kit[index] - K;
			if (weight < 500) break;
		}
		if (i == N) cnt++;
	} while (next_permutation(num.begin(), num.end()));
	cout << cnt << endl;
	return 0;
}