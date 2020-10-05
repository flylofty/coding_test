#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 987654321;
int n = 0;
int d = 0;
int c = 0;

vector<vector<pair<int, int>>> g;

void input()
{
	cin >> n >> d >> c;
	g.assign(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < d; ++i)
	{
		int a; pair<int, int> p;
		cin >> p.first >> a >> p.second;
		g[a].push_back(p);
	}
}

void findanswer()
{
	int Max = 0;
	int cnt = 0;

	vector<int> D(n + 1, INF);
	D[c] = 0;

	queue<pair<int, int>> q;
	q.push({c, 0});

	while (!q.empty())
	{
		int n1 = q.front().first;
		int cost = q.front().second;
		q.pop();

		/*if (D[n1] < cost)
			continue;*/

		for (int i = 0; i < g[n1].size(); ++i)
		{
			int n2 = g[n1][i].first;
			int sum = cost + g[n1][i].second;

			if (D[n2] > sum)
			{
				D[n2] = sum;
				q.push({n2, sum});
			}
		}
	}

	//cout << endl; cout << endl;
	for (int i = 1; i <= n; ++i)
	{
		//cout << D[i] << " ";
		if (D[i] != INF)
		{
			if (Max < D[i])
				Max = D[i];
			cnt++;
		}
	}
	//cout << endl; cout << endl;

	cout << cnt << " " << Max << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t = 0;
	cin >> t;

	while (t--)
	{
		input();
		findanswer();
	}

	return 0;
}