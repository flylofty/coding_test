#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int L = 0;
vector<int> v;

void input()
{
	cin >> N >> L;
	v.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
}

void findAnwer()
{
	int left = v[0];
	int cnt = 1;

	for (int i = 1; i < N; ++i)
	{
		if (v[i] - left >= L)
		{
			left = v[i];
			cnt++;
		}
	}

	cout << cnt << "\n";
}

int main()
{
	input();
	findAnwer();
	return 0;
}