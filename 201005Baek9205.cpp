#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<vector<int>> graph;
bool isPossible = false;
vector<bool> visit;

void input()
{
	cin >> n;
	vector<vector<int>> v(n + 2, vector<int>(2, 0));
	for (int i = 0; i < n + 2; ++i)
		cin >> v[i][0] >> v[i][1];

	graph.assign(n + 2, vector<int>(n + 2, 0));
	for (int i = 0; i < n + 1; ++i)
	{
		for (int j = 0; j < n + 2; ++j)
		{
			if (i != j && abs(v[i][0] - v[j][0]) + abs(v[i][1] - v[j][1]) <= 1000)
				graph[i][j] = 1;
		}
	}

	// for (int i = 0; i < n + 1; ++i)
	// {
	// 	for (int j = 0; j < n + 2; ++j)
	// 	{
	// 		cout << graph[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n"; cout << "\n";
}

void findAnswer(int node, int des)
{
	visit[node] = true;

	if (node == des)
	{
		isPossible = true;
		return;
	}

	for (int i = 0; i < n + 2; ++i)
	{
		if (graph[node][i] && !visit[i])
		{
			findAnswer(i, des);
		}
	}
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		input();

		isPossible = false;
		visit.assign(n + 2, false);

		findAnswer(0, n + 1);

		if (isPossible)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}