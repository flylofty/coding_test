#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<vector<int>> v;
int white = 0;
int blue = 0;

void input()
{
	cin >> N;
	v.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}
}

vector<int> findAnswer(int y1, int y2, int x1, int x2)
{
	vector<int> temp(2, 0);

	if (y2 - y1 == 1 && x2 - x1 == 1)
	{
		if (v[x1][y1] == 0)
		{
			temp[0]++;
		}
		else
		{
			temp[1]++;
		}
		return temp;
	}

	vector<vector<int>> r;
	r.push_back(findAnswer(y1, (y2 + y1) / 2, x1, (x2 + x1) / 2));
	r.push_back(findAnswer((y2 + y1) / 2, y2, x1, (x2 + x1) / 2));
	r.push_back(findAnswer(y1, (y2 + y1) / 2, (x2 + x1) / 2, x2));
	r.push_back(findAnswer((y2 + y1) / 2, y2, (x2 + x1) / 2, x2));


	for (int i = 0; i < 4; ++i)
	{
		temp[0] += r[i][0];
		temp[1] += r[i][1];
	}

	if (temp[0] == 4 && temp[1] == 0)
		temp[0] = 1;
	if (temp[1] == 4 && temp[0] == 0)
		temp[1] = 1;

	return temp;
}

int main()
{
	input();
	vector<int> v;
	v = findAnswer(0, N, 0, N);

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";

	return 0;
}