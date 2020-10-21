#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T = 0;
	int K = 0;
	priority_queue<long, vector<long>, greater<long>> q;
	vector<long> answer;

	cin >> T;

	while (T--)
	{
		cin >> K;
		for (int i = 0; i < K; ++i)
		{
			int f; cin >> f;
			q.push(f);
		}

		long sum = 0;
		while (q.size() > 1)
		{
			long a = q.top();
			q.pop();
			long b = q.top();
			q.pop();

			sum += a + b;

			q.push(a + b);
		}

		cout << sum << "\n";
		
		while (!q.empty())
			q.pop();
	}

	return 0;
}