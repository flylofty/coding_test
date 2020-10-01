#include <iostream>
#include <vector>
#include <string>

using namespace std;

string S;
int N = 0;
bool isFind = false;

void findAnswer(int pre, vector<bool>temp, vector<int> v)
{
	if (isFind)
		return;

	if (v.size() == N)
	{
		for (int i = 0; i < N; ++i)
			cout << v[i] << " ";
		cout << "\n";
		isFind = true;
		return;
	}

	string s;
	int num;
	for (int i = pre + 1; i < pre + 3 && i < S.size(); ++i)
	{
		s.push_back(S[i]);
		num = stoi(s);

		if (num >= N + 1)
			continue;

		if (!temp[num])
		{
			temp[num] = true;
			v.push_back(num);
			findAnswer(i, temp, v);
			v.pop_back();
			temp[num] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> S;

	if (S.size() <= 9)
		N = S.size();
	else
		N = ((S.size() - 9) / 2 + 9);

	vector<bool> isIn(N + 1, false);
	isIn[0] = true;
	vector<int> v;

	findAnswer(-1, isIn, v);
	return 0;
}