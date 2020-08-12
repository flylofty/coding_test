#include <iostream>

using namespace std;

int R, C;
char card[101][101];

int main() {

	cin >> R >> C;
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cin >> card[i][j];
		}
	}

	int A, B;
	cin >> A >> B;

	R *= 2, C *= 2;

	for (int i = 1; i <= R / 2; ++i) { // 1사분면
		for (int j = 1; j <= C / 2; ++j) {
			card[i][C - j + 1] = card[i][j];
		}
	}

	for (int i = 1; i <= R/2; ++i) { // 3사분면
		for (int j = 1; j <= C; ++j) {
			card[R - i + 1][j] = card[i][j];
		}
	}

	if (card[A][B] == '.') {
		card[A][B] = '#';
	}
	else {
		card[A][B] = '.';
	}

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			cout << card[i][j];
		}
		cout << "\n";
	}

	return 0;
}