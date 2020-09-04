#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// true == White,  false == Black
vector<bool> A[51];
vector<bool> B[51];
vector<bool> C[51];
int N = 0;
int M = 0;
int Min = 64;

void init() {
	int temp = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i % 2 == 0) {
				if (temp % 2 == 0) {
					A[i].push_back(true);
					B[i].push_back(false);
				}
				else {
					A[i].push_back(false);
					B[i].push_back(true);
				}
			}
			else {
				if (temp % 2 == 0) {
					A[i].push_back(false);
					B[i].push_back(true);
				}
				else {
					A[i].push_back(true);
					B[i].push_back(false);
				}
			}
			temp++;
		}
	}

	for (int i = 0; i < N; ++i) {
		C[i].assign(M, true);
		for (int j = 0; j < M; ++j) {
			char ch; cin >> ch;
			if (ch == 'W') C[i][j] = true;
			else C[i][j] = false;
		}
	}
}

int findMin(int x, int y) {

	int a = 0, b = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (A[i][j] != C[i + x][j + y]) a++;
			if (B[i][j] != C[i + x][j + y]) b++;
		}
	}

	return ((a <= b) ? a : b);
}

int main() {

	cin >> N >> M;
	init();
	for (int i = 0; i <= N - 8; ++i) {
		for (int j = 0; j <= M - 8; ++j) {
			Min = min(Min, findMin(i, j));
		}
	}
	cout << Min << "\n";
	return 0;
}