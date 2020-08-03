#include <iostream>

using namespace std;

int main() {

	int bar = 64;
	int X = 0;
	cin >> X;

	int cnt = 0;

	while (X != 0) {

		if (bar > X) {
			bar = bar / 2;
		}
		else {
			X = X - bar;
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}