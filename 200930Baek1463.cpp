#include <iostream>
#include <queue>

using namespace std;

int X = 0;

void BFS(int s)
{
	queue<pair<int, int>> q;
	q.push({s, 0});

	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == 1)
		{
			cout << cnt << endl;
			return;
		}

		if (x % 3 == 0)
		{
			q.push({x / 3, cnt + 1});
		}
		
		if (x % 2 == 0)
		{
			q.push({ x / 2, cnt + 1 });
		}

		if (x > 2)
		{
			q.push({ x - 1, cnt + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> X;
	BFS(X);
	return 0;
}