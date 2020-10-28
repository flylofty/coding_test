#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
vector<int> num;
vector<int> op;

void input()
{
	cin >> N;
	num.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		int t; cin >> t;
		for (int j = 0; j < t; ++j)
		{
			op.push_back(i);
		}
	}
}

void findAnswer()
{
	int Max = -1000000000;
	int Min = 1000000000;
	do {

		vector<int> temp;
		temp.clear();
		temp = num;
		for (int i = 0; i < op.size(); ++i)
		{
			int c = op[i];

			if (c == 3 && temp[i + 1] == 0)
				continue;

			if (c == 0)
			{
				temp[i + 1] = temp[i] + temp[i + 1];
			}
			else if (c == 1)
			{
				temp[i + 1] = temp[i] - temp[i + 1];
			}
			else if (c == 2)
			{
				temp[i + 1] = temp[i] * temp[i + 1];
			}
			else
			{
				temp[i + 1] = temp[i] / temp[i + 1];
			}
		}

		if (temp[N - 1] > Max)
			Max = temp[N - 1];
		if (temp[N - 1] < Min)
			Min = temp[N - 1];

	} while (next_permutation(op.begin(), op.end()));

	cout << Max << "\n";
	cout << Min << "\n";
}

int main()
{
	input();
	findAnswer();
	return 0;
}