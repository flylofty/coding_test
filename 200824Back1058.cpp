#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 0;

int main() {

	cin >> N;
	vector<string> f(N);
	for (int i = 0; i < N; ++i) cin >> f[i];

	int Max = 0;

	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			if (f[i][j] == 'Y') {
				cnt++;
			}
			else {
				int mate = j;
				for (int k = 0; k < N; ++k) {
					if (k == i) continue;
					if (f[i][k] == 'Y' && f[mate][k] == 'Y') {
						cnt++;
						break;
					}
				}
			}
		}
		if (cnt > Max)
			Max = cnt;
	}

	cout << Max << endl;
	return 0;
}