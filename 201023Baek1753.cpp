#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V = 0;
int E = 0;
int K = 0;
//vector<vector<pair<int, int>>> g; // Vertex, Weight
vector<pair<int, int>> g[20001];

void input()
{
	cin >> V >> E;
	cin >> K;

	// g.assign(V + 1, vector<pair<int, int>>());
	for (int i = 0; i < E; ++i)
	{
		int u, v, w; cin >> u >> v >> w;
		// g[v].push_back({ u, w });
		g[u].push_back({ v, w });
	}
}

void DijkstraShortestPath()
{
	int INF = 987654321;
	vector<int> D(V + 1, INF);
	D[K] = 0;
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, K});

	while (!pq.empty())
	{
		int x = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (D[x] < cost)
			continue;

		for (int i = 0; i < g[x].size(); ++i)
		{
			int y = g[x][i].first;
			int x_y = cost + g[x][i].second;

			if (D[y] > x_y)
			{
				D[y] = x_y;
				pq.push({ x_y, y });
			}
		}
	}

	for (int i = 1; i <= V; ++i)
	{
		if (D[i] == INF)
			cout << "INF\n";
		else
			cout << D[i] << "\n";
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	DijkstraShortestPath();
	return 0;
}