#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

vector<vector<pair<int, int>>> g;
vector<vector<int>> v;
vector<pair<int, int>> know;

void intput()
{
	cin >> N >> M;
	g.assign(N + 1, vector<pair<int, int>>());
	int a, b, c;
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
	}

	v.assign(N + 1, vector<int>(N + 1, 987654321));
	for (int i = 1; i < g.size(); ++i)
	{
		for (int j = 0; j < g[i].size(); ++j)
		{
			v[i][g[i][j].first] = g[i][j].second;
		}
		v[i][i] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		know.push_back({ a, b });
	}

}

void findAnswer()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (v[i][k] + v[k][j] < v[i][j])
				{
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	//for (int i = 1; i <= N; ++i)
	//{
	//	for (int j = 1; j <= N; ++j)
	//	{
	//		cout << v[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for (int i = 0; i < know.size(); ++i)
	{
		cout << v[know[i].first][know[i].second] << "\n";
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	intput();
	findAnswer();
	return 0;
}