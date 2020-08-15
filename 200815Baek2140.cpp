#include <iostream>

using namespace std;

int N, cnt = 0;
char board[101][101]{NULL};

void input() {
	cin >> N;

	if (N - 2 > 0)
		cnt = (N - 2)*(N - 2);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
}

bool isZero(int i, int j) {

	for (int x = i - 1; x < i + 2; ++x) {
		for (int y = j - 1; y < j + 2; ++y) {
			if (x == i && y == j) continue;
			if (board[x][y] == '0') {
				return true;
			}
		}
	}
	return false;
}

void find_Adjacent() {

	for (int i = 1; i < N - 1; ++i) {
		for (int j = 1; j < N - 1; ++j) {
			if (!isZero(i, j)) { // 주변에 0이 없을 경우
				for (int x = i - 1; x < i + 2; ++x) {
					for (int y = j - 1; y < j + 2; ++y) {
						if (x == i && y == j) continue;
						if (board[x][y] >= '1' && board[x][y] <= '3') {
							board[x][y]--;
						}
					}
				}
			}
			else {
				cnt--;
			}
		}
	}
	cout << cnt << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	find_Adjacent();
	return 0;
}