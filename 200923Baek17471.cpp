#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 0;
vector<int> gu(11, 0);
vector<int> adj[11];
int Min = 900;
int sum2 = 0;

bool isConnected(vector<int> v, vector<bool> location, bool near) // BFS
{
	queue<int> q;
	q.push(v[0]);
	vector<int> visit(N + 1, false);
	visit[v[0]] = true;

	int cnt = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 0; i < adj[x].size(); ++i)
		{
			int n_x = adj[x][i];

			if (!visit[n_x] && location[n_x] == near)
			{
				q.push(n_x);
				visit[n_x] = true;
				cnt++;
			}
		}
	}


	if (cnt == v.size())
		return true;
	else
		return false;
}

void findMin(vector<bool> temp)
{
	vector<int> V1;
	vector<int> V2;
	int a = 0;
	int b = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (temp[i])
		{
			V1.push_back(i);
			a += gu[i];
		}
		else
		{
			V2.push_back(i);
			b += gu[i];
		}
	}

	cout << "\n=========================\n";
	for (int i = 0; i < V1.size(); ++i)
	{
		cout << V1[i] << " ";
	}
	cout << "\n--------------------------\n";
	for (int i = 0; i < V2.size(); ++i)
	{
		cout << V2[i] << " ";
	}
	cout << "\n=========================\n";

	sum2++;

	if (!isConnected(V1, temp, true)) return;
	if (!isConnected(V2, temp, false)) return;

	int r;
	if (a < b) r = b - a;
	else r = a - b;

	if (Min < r) return;
	Min = r;
}

void divide(int M, int pre, int cnt, vector<bool> temp)
{
	if (cnt < M)
	{
		for (int i = pre + 1; i <= N; ++i)
		{
			temp[i] = true;
			divide(M, i, cnt + 1, temp);
			temp[i] = false;
		}
	}
	else
	{
		findMin(temp);
	}
}

void findAnswer() {

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> gu[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		int num; 
		cin >> num;
		for (int j = 0; j < num; ++j)
		{
			int v; cin >> v;
			adj[i].push_back(v);
		}
	}

	for (int i = 1; i <= N / 2; ++i)
	{
		vector<bool> temp(N + 1, false);
		divide(i, 0, 0, temp);
	}
}

int main() {

	findAnswer();
	cout << "\n cnt: " << sum2 << endl;

	if (Min == 900)
		cout << "-1\n";
	else
		cout << Min << "\n";

	return 0;
}