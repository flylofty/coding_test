#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> store(N, 0);
	int milk[3]{0, 1, 2};
	int turn = 0;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cin >> store[i];
		if (store[i] == milk[turn % 3]) {
			turn++;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}