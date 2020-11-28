#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	int dasom = 0;
	cin >> dasom;

	priority_queue<int, vector<int>> pq;

	for (int i = 0; i < N - 1; ++i)
	{
		int num; cin >> num;
		pq.push(num);
	}

	if (pq.empty())
		pq.push(0);

	int cnt = 0;

	while (dasom + cnt <= pq.top())
	{
		int t = pq.top();
		pq.pop();
		cnt++;
		t--;
		
		if (t > 0)
			pq.push(t);
	}

	cout << cnt << "\n";

	return 0;
}