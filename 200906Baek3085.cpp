#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int findMax(vector<vector<char>> B, int o_x, int o_y, int x, int y) {

	char ch = B[o_x][o_y];
	B[o_x][o_y] = B[x][y];
	B[x][y] = ch;

	int up = 0;
	for (int i = x - 1; i >= 0; --i)
	{
		if (B[i][y] == ch) up++;
		else break;
	}

	int down = 0;
	for (int i = x + 1; i < N; ++i)
	{
		if (B[i][y] == ch) down++;
		else break;
	}

	int left = 0;
	for (int i = y - 1; i >= 0; --i)
	{
		if (B[x][i] == ch) left++;
		else break;
	}

	int right = 0;
	for (int i = y + 1; i < N; ++i)
	{
		if (B[x][i] == ch) right++;
		else break;
	}

	int r = up + down;
	int c = left + right;

	return (r > c ? r + 1 : c + 1);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	vector<vector<char>> B(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> B[i][j];
		}
	}

	int Max = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {

			for (int k = 0; k < 4; ++k)
			{
				int adj_x = i + dir[k][0];
				int adj_y = j + dir[k][1];

				if (adj_x >= 0 && adj_x < N && adj_y >= 0 && adj_y < N)
				{
					Max = max(Max, findMax(B, i, j, adj_x, adj_y));
					// int temp = findMax(B, i, j, adj_x, adj_y);
					// cout << B[i][j] << " " << temp << "  " << i << " " << j << " ==> " << adj_x << " " << adj_y << endl;
				}
			}

		}
	}

	cout << Max << "\n";
	return 0;
}