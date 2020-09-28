#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N = 0;
vector<int> v;
map<int, pair<bool, int>> isIn;

void findAll(vector<int> temp, int cnt, int pre)
{
	if (temp.size() < 2)
	{
		for (int i = pre + 1; i < N; ++i)
		{
			temp.push_back(i);
			findAll(temp, cnt + 1, i);
			temp.pop_back();
		}
	}
	else
	{
		auto it = isIn.find(v[temp[0]] + v[temp[1]]);

		if (it == isIn.end())
			return;
		
		for (int i = 0; i < 2; ++i)
		{
			if (it->second.second == temp[i])
				return;
		}

		it->second.first = true;
	}
}

void input()
{
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
		isIn[v[i]] = { false, i };
	}
}

int main()
{
	input();
	vector<int> temp;
	findAll(temp, 0, -1);

	int answer = 0;
	for (int i = 0; i < N; ++i)
	{
		if (isIn[v[i]].first)
			answer++;
	}
	cout << answer << "\n";
	return 0;
}