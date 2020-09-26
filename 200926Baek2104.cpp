#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<long long> v;

long long findAnswer(int left, int right)
{
	if (left == right)
	{
		return v[left] * v[left];
	}

	int mid = (left + right) / 2;
	long long Max = max(findAnswer(left, mid), findAnswer(mid + 1, right));
	
	int s = mid;
	int e = mid + 1;
	long long Min = min(v[s], v[e]);
	long long sum = v[s] + v[e];
	Max = max(Max, sum * Min);

	while (s > left || e < right)
	{
		if (e < right && (s == left || v[s - 1] < v[e + 1]))
		{
			Min = min(Min, v[e + 1]);
			sum += v[++e];
		}
		else
		{
			Min = min(Min, v[s - 1]);
			sum += v[--s];
		}
		Max = max(Max, sum * Min);
	}
	return Max;
}

void input() 
{
	cin >> N;
	v.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i)
		cin >> v[i];
}

int main() 
{
	input();
	cout << findAnswer(1, N) << "\n";
	return 0;
}