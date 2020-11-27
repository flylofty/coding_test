#include <iostream>
#include <queue>

using namespace std;

int n = 0;
int m = 0;
priority_queue<long, vector<long>, greater<long>> q;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int num; cin >> num;
		q.push(num);
	}

	int cnt = 0;
	long sum = 0;
	while (cnt < m)
	{
		int cnt2 = 0;
		sum = 0;
		while (!q.empty())
		{
			sum += q.top();
			q.pop();

			cnt2++;
			if (cnt2 == 2)
				break;
		}

		q.push(sum);
		q.push(sum);

		cnt++;
	}

	sum = 0;
	while (!q.empty())
	{
		sum += q.top();
		q.pop();
	}

	cout << sum << "\n";

	return 0;
}