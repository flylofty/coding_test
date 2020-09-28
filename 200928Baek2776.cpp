#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T = 0;
int N = 0;
vector<int> v;
int M = 0;

bool findNumber(int num)
{
	int left = 0;
	int right = N - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (v[mid] == num)
			return true;
		else if (v[mid] < num)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		v.assign(N, 0);
		for (int i = 0; i < N; ++i)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		cin >> M;
		int k;
		for (int j = 0; j < M; ++j)
		{
			cin >> k;
			cout << findNumber(k) << "\n";
		}
	}

	return 0;
}