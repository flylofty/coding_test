#include <iostream>

using namespace std;

int main() {

	while (1) {
		int N;
		cin >> N;
		if (N == 0) break;
		cout << (N * (N + 1) * (2 * N + 1)) / 6 << "\n";
	}

	return 0;
}