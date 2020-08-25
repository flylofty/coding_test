#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N = 0;
	int find;
	int a, b;
	int dir[4][2]{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	cin >> N;
	cin >> find;
	vector<vector<int>> arr(N, vector<int>(N, 0));

	int cnt = N * N;
	int x = -1;
	int y = 0;

	int index = 0;
	for (int i = N; i > 0; --i) {

		for (int j = i; j > 0; --j) {
			x = x + dir[index % 4][0];
			y = y + dir[index % 4][1];

			if (find == cnt) {
				a = x;
				b = y;
			}

			arr[x][y] = cnt--;
		}

		--i;
		++index;

		for (int j = i; j > 0; --j) {
			x = x + dir[index % 4][0];
			y = y + dir[index % 4][1];

			if (find == cnt) {
				a = x;
				b = y;
			}

			arr[x][y] = cnt--;
		}

		++i;
		++index;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << a+1 << " " << b+1 << "\n";

	return 0;
}