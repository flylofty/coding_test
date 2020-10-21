#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<int> v1;
vector<int> v2;

void findAnswer()
{
	cin >> N;
	v1.assign(N + 1, 0);
	v2.assign(N + 1, 0);
	for (int i = 1; i <= N; ++i)
	{
		cin >> v1[i];
	}

	int size = 0;
	v2[0] = v1[1];
	for (int i = 2; i <= N; ++i)
	{
		if (v2[size] < v1[i])
		{
			v2[++size] = v1[i];
		}
		else
		{
			int index = lower_bound(v2.begin(), v2.begin() + size, v1[i]) - v2.begin();
			v2[index] = v1[i];
		}
	}
	cout << size + 1 << "\n";
}

int main()
{
	findAnswer();
	return 0;
}