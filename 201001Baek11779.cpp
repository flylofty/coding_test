#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
int M = 0;
vector<pair<int, int>> city[1001];
int from = 0;
int to = 0;

void input()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back({ b, c });
	}
	cin >> from >> to;
}

void Dijkstra()
{
	vector<int> D;
	D.assign(N + 1, 987654321);
	D[from] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ from, 0 });

	vector<int> visit(N + 1, 0);

	while (!pq.empty())
	{
		int x = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (D[x] < cost)
			continue;

		for (int i = 0; i < city[x].size(); ++i)
		{
			int y = city[x][i].first;
			int sum = cost + city[x][i].second;

			if (D[y] > sum)
			{
				D[y] = sum;
				pq.push({ y, sum });
				visit[y] = x;
			}
		}
	}

	cout << D[to] << "\n";

	vector<int> path;
	int Temp = to;
	while (Temp)
	{
		path.push_back(Temp);
		Temp = visit[Temp];
	}
	cout << path.size() << "\n";
	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << " ";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	Dijkstra();
	return 0;
}