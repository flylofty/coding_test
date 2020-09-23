#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int M = 0;
vector<int> adj[1001];
vector<bool> visit;
int cnt = 0;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < adj[x].size(); ++i)
		{
			int n_x = adj[x][i];

			if (!visit[n_x])
			{
				q.push(n_x);
				visit[n_x] = true;
			}

		}
	}
}

void findAnswer()
{
	for (int i = 1; i <= N; ++i)
	{
		if (!visit[i])
		{
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";
}

void input()
{
	cin >> N >> M;

	visit.assign(N + 1, false);

	for (int i = 0; i < M; ++i)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	findAnswer();

	return 0;
}