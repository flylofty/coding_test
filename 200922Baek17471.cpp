#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N = 0;
int total = 0;
vector<int> gu(11, 0);
vector<int> adj[11];
int sum = 0;
set<int> isReal;
int Min = 900;

bool findWay(int s, int m, int e, vector<bool> way)
{
	if (m == e)
	{
		return true;
	}

	for (int i = 0; i < adj[m].size(); ++i)
	{
		if (way[adj[m][i]])
		{
			way[adj[m][i]] = false;
			if (findWay(s, adj[m][i], e, way))
				return true;
			way[adj[m][i]] = true;
		}
	}

	return false;
}

void bruteForce(int cnt, vector<int> temp, set<int> s) {

	if (temp.empty())
	{
		for (int i = 1; i <= N; ++i)
		{
			temp.push_back(i);
			s.insert(i);
			bruteForce(cnt, temp, s);
			s.erase(i);
			temp.pop_back();
		}
	}
	else if (temp.size() < cnt)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (temp[temp.size() - 1] < i)
			{
				temp.push_back(i);
				s.insert(i);
				bruteForce(cnt, temp, s);
				s.erase(i);
				temp.pop_back();
			}
		}
	}
	else if (temp.size() == cnt)
	{
		vector<int> temp2;
		int t1 = 0;
		int t2 = 0;
		int a = 0;
		int b = 0;
		vector<bool> T1(N + 1, false);
		vector<bool> T2(N + 1, false);
		for (int i = 1; i <= N; ++i)
		{
			if (s.find(i) == s.end())
			{
				t2 += gu[i];
				a = a * 10 + i;
				temp2.push_back(i);
				T2[i] = true;
			}
			else
			{
				t1 += gu[i];
				b = b * 10 + i;
				T1[i] = true;
			}
		}

		if (isReal.find(a) == isReal.end())
		{
			isReal.insert(a);
		}

		if (isReal.find(b) != isReal.end())
		{
			return;
		}

		int j = 0;
		bool isReach = false;
		for (; j < temp.size(); ++j)
		{
			
			for (int k = j + 1; k < temp.size(); ++k)
			{
				if (!findWay(temp2[j], temp2[j], temp2[k], T1))
				{
					isReach = false;
					break;
				}

				if (!isReach)
					break;
			}
		}

		if (j != temp.size())
			return;

		j = 0;
		isReach = true;
		for (; j < temp2.size(); ++j)
		{
			for (int k = j + 1; k < temp2.size(); ++k)
			{
				if (!findWay(temp2[j], temp2[j], temp2[k], T2))
				{
					isReach = false;
					break;
				}
			}

			if (!isReach)
				break;
		}

		if (j != temp2.size())
			return;

		int r = 0;
		if (t1 > t2)
			r = t1 - t2;
		else
			r = t2 - t1;

		if (Min < r)
			return;

		Min = r;
	}
}

void input() {
	cin >> N;
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> gu[i];
		total += gu[i];
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
		sort(adj[i].begin(), adj[i].end());
	}

	for (int i = 1; i <= N/2; ++i)
	{
		vector<int> v;
		set<int> s;
		bruteForce(i, v, s);
	}
}

int main() {

	input();

	if (Min == 900)
		cout << "-1\n";
	else
		cout << Min << "\n";

	return 0;
}