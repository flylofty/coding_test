#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int k;
	vector<int> s(13, 0);
	bool check_permutation[13];
	vector <vector<int>> answer;
	vector<int> vec;

	while (cin >> k) {

		if (k == 0) break;

		for (int i = 0; i < k; ++i) {
			cin >> s[i];
		}

		for (int i = 0; i < k - 6; ++i) {
			check_permutation[i] = false;
		}

		for (int i = k - 6; i < k; ++i) {
			check_permutation[i] = true;
		}

		do {

			for (int i = 0; i < k; ++i) {
				cout << check_permutation[i] << " ";
			}
			cout << endl;
			cout << "check_permutation" << endl;
			cout << endl;

			for (int i = 0; i < k; ++i) {
				if (check_permutation[i]) {
					vec.push_back(s[i]);
				}
			}

			answer.push_back(vec);
			vec.clear();
		} while (next_permutation(check_permutation, check_permutation + k));

		sort(answer.begin(), answer.end());
		for (auto it : answer) {
			for (int i = 0; i < it.size(); ++i) {
				cout << it[i] << " ";
			}
			cout << endl;
		}
		answer.clear();
		cout << endl;

	}

	return 0;
}