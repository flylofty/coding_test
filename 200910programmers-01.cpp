#include <Iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<vector<int>> v;

void dfs(vector<int> temp, int limit)
{
	if (temp.size() < limit)
	{
		for (int i = 0; i < n; ++i)
		{
			if (temp.empty() || temp.back() < i)
			{
				temp.push_back(i);
				dfs(temp, limit);
				temp.pop_back();
			}
		}
	}
	else if (temp.size() == limit)
	{
		v.push_back(temp);
		return;
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;

	n = relation[0].size();
	for (int i = 1; i <= n; ++i)
	{
		vector<int> temp;
		dfs(temp, i);
	}

	for (int a = 0; a < v.size(); ++a)
	{

		if (v[a].empty())
			continue;

		int cnt = 0;

		for (int b = 0; b < v[a].size(); ++b)
		{
			cout << v[a][b] << " ";
		}
		cout << endl;

		for (int i = 0; i < relation.size(); ++i)
		{
			string s1;
			for (int b = 0; b < v[a].size(); ++b) 
			{
				s1 += relation[i][v[a][b]];
			}

			for (int j = i + 1; j < relation.size(); ++j)
			{	
				string s2;
				for (int b = 0; b < v[a].size(); ++b) s2 += relation[j][v[a][b]];

				cout << s1 << "  " << s2 << endl;

				if (s1 == s2)
					cnt++;

				s2.clear();

			}

			if (cnt > 0) {
				cout << endl;
				break;
			}

			s1.clear();
		}

		if (cnt == 0)
		{
			vector<int> temp2 = v[a];
			int vSize = v[a].size();
			for (int c = 0; c < v.size(); ++c)
			{
				if (c == a)
				{
					v[c].clear();
					continue;
				}
				int cnt = 0;
				for (int d = 0; d < temp2.size(); ++d)
				{
					for (int e = 0; e < v[c].size(); ++e)
					{
						if (temp2[d] == v[c][e])
							cnt++;
					}
				}
				if (vSize == cnt)
					v[c].clear();
			}

			answer++;
		}
	}

	return answer;
}

int main() {

	//vector<vector<string>> relation{ {"100",  "ryan",   "music",    "2"},
	//                                 {"200",  "apeach", "math",     "2"},
	//                                 {"300",  "tube",   "computer", "3"},
	//                                 {"400",  "con",    "computer", "4"},
	//                                 {"500",  "muzi",   "music",    "3"},
	//                                 {"600",  "apeach", "music",    "2"} };

	vector<vector<string>> relation{ {"a", "1", "3"},
									 {"2", "1", "5"},
									 {"a", "2", "4"}};

	cout << solution(relation) << endl;
	return 0;
}