#include <iostream>
#include <vector>
using namespace std;

int g_min = 64;
int g_M = 0;
int g_N = 0;

int find_min(vector<vector<char>> &v, const int x, const int y)
{
	char left = v[x][y];
	char right;

	if (left == 'W')
		right = 'B';
	else
		right = 'W';

	int cnt = 0;
	int cnt2 = 0;

	for (int i = x; i < x + 8; ++i)
	{
		for (int j = y; j < y + 8; ++j)
		{
			if ((i - x) % 2 == 0)
			{
				if ((j - y) % 2 == 0)
				{
					if (v[i][j] != left)
						cnt += 1;
					else
						cnt2 += 1;
				}
				else
				{
					if (v[i][j] != right)
						cnt += 1;
					else
						cnt2 += 1;
				}
			}
			else
			{
				if ((j - y) % 2 == 0)
				{
					if (v[i][j] != right)
						cnt += 1;
					else
						cnt2 += 1;
				}
				else
				{
					if (v[i][j] != left)
						cnt += 1;
					else
						cnt2 += 1;
				}
			}
		}
	}

	if (cnt < cnt2)
		return cnt;
	else
		return cnt2;
}

void solution(vector<vector<char>> &v)
{
	for (int i = 0; i < g_M; ++i)
	{
		for (int j = 0; j < g_N; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < g_M; ++i)
	{
		if (i + 7 >= g_M)
			break;

		for (int j = 0; j < g_N; ++j)
		{
			if (j + 7 >= g_N)
				break;

			int min = find_min(v, i, j);

			if (min < g_min)
				g_min = min;
		}
	}

	cout << g_min << endl;

}

int main()
{
	cin >> g_M >> g_N;
	vector<vector<char>> v(g_M, vector<char>(g_N));
	solution(v);

	return 0;
}