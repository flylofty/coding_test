#include <iostream>
#include <vector>

using namespace std;

int T = 0;
int N = 0;
vector<vector<int>> g;
vector<bool> c;

void input()
{
	cin >> N;
	g.assign(N + 1, vector<int>());
	c.assign(N + 1, false);
	for (int i = 1; i <= N; ++i)
	{
		int node; cin >> node;
		g[i].push_back(node);
	}
}

void DFS(int s)
{
	c[s] = true;

	for (int i = 0; i < g[s].size(); ++i)
	{
		int node = g[s][i];
		if (!c[node])
		{
			DFS(node);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;

	while (T--)
	{
		input();
		int cnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (!c[i])
			{
				DFS(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}