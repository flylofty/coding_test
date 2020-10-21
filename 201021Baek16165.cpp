#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N = 0;
int M = 0;
map<string, int> m1;
map<string, string> m2;
vector<string> g[100];

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string gName; cin >> gName;
		int num; cin >> num;

		m1[gName] = i;

		for (int j = 0; j < num; ++j)
		{
			string name; cin >> name;
			g[i].push_back(name);
			m2[name] = gName;
		}

		sort(g[i].begin(), g[i].end());
	}

}

void findAnswer()
{
	string name; 
	int q;

	for (int i = 0; i < M; ++i)
	{
		cin >> name;
		cin >> q;

		if (q == 0) // 이름 사전순 출력
		{
			int index = m1[name];
			for (int j = 0; j < g[index].size(); ++j)
			{
				cout << g[index][j] << "\n";
			}
		}
		else
		{
			cout << m2[name] << "\n";
		}
	}
}

int main()
{
	input();
	findAnswer();
	return 0;
}