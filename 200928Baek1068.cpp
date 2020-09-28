#include <iostream>
#include <vector>

using namespace std;

vector<int> v[50];
int N = 0;
int del = 0;
int answer = 0;
int root = 0;

void input()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int p = 0;
		cin >> p;
		
		if (p == -1)
		{
			root = i;
		}
		else
		{
			v[p].push_back(i);
		}
	}

	cin >> del;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == del)
			{
				v[i].erase(v[i].begin() + j);
			}
		}

		if (v[i].size() == 0)
			answer++;
	}

}

void findAnswer(int node)
{
	if (v[node].size() == 0)
	{
		answer--;
		return;
	}
	for (int i = 0; i < v[node].size(); ++i)
	{
		findAnswer(v[node][i]);
	}
}

int main() 
{
	input();

	if (del == root)
	{
		cout << "0\n";
	}
	else
	{
		findAnswer(del);
		cout << answer << "\n";
	}

	return 0;
}