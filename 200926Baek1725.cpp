#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> v;

int findAnswer(int left, int right)
{
	if (left == right)
	{
		return v[right];
	}

	int mid = (left + right) / 2;
	int Max = max(findAnswer(left, mid), findAnswer(mid + 1, right));

	int s = mid;
	int e = mid + 1;

	int h = min(v[e], v[s]);
	Max = max(Max, h * (e - s + 1));

	while (s > left || e < right)
	{
		if (e < right && (s == left || v[s - 1] < v[e + 1]))
		{
			h = min(h, v[++e]);
		}
		else
		{
			h = min(h, v[--s]);
		}

		Max = max(Max, h * (e - s + 1));
	}

	return Max;
}

void input() 
{
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
}

int main()
{
	input();
	cout << findAnswer(0, N - 1) << "\n";

	return 0;
}