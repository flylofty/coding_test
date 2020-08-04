#include <iostream>
#include <vector>

using namespace std;

int main() {
	int max = 0;

	vector<int> cases;
	while (1) {
		int n;
		cin >> n;

		if (n == 0) {
			break;
		}
		cases.push_back(n);

		if (max < n) {
			max = n;
		}
	}

	vector<bool> num(max * 2 + 1, true);
	num[1] = false;
	for (int i = 2; i <= max * 2; ++i) {
		int mul = 2;
		if (num[i]) {
			while (i*mul <= max * 2) {
				num[i*mul] = false;
				mul++;
			}
		}
	}

	for (int i = 0; i < cases.size(); ++i) {
		int cnt = 0;
		for (int j = cases[i] + 1; j <= cases[i] * 2; ++j) {
			if (num[j]) {
				//cout << j << "\n";
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}