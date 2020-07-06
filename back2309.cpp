#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	const int n = 9;
	vector<int> dwarfs(9, 0);
	bool check_permutation[9];
	vector<int> answer;

	for (int i = 0; i < n; ++i) {
		cin >> dwarfs[i];
	}

	sort(dwarfs.begin(), dwarfs.end());

	for (int i = 0; i < n - 7; ++i) {
		check_permutation[i] = false;
	}

	for (int i = n - 7; i < n; ++i) {
		check_permutation[i] = true;
	}

	do {

		int sum = 0;

		for (int i = 0; i < n; ++i) {
			if (check_permutation[i]) {
				answer.push_back(dwarfs[i]);
				sum += dwarfs[i];
			}
		}

		if (sum == 100) {

			for (int i = 0; i < answer.size(); ++i) {
				cout << answer[i] << endl;
			}

			break;
		}


		answer.clear();
	} while (next_permutation(check_permutation, check_permutation + n));


	return 0;
}