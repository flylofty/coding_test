#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;

int main() {

	cin >> N;
	vector<int> stick(N);
	for (int i = 0; i < N; ++i) {
		cin >> stick[i];
	}

	int Max = 0;
	int cnt = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (stick[i] > Max) {
			cnt++;
			Max = stick[i];
		}
	}
	cout << cnt << endl;
	return 0;
}