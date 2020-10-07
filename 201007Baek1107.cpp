#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ch = 0;
vector<int> remote;
int Min = 0;

void input()
{
	cin >> ch;

	Min = abs(ch - 100);

	int w = 0;
	cin >> w;

	vector<bool> isIn(10, true);
	for (int i = 0; i < w; ++i)
	{
		int num; cin >> num;
		isIn[num] = false;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (isIn[i])
			remote.push_back(i);
	}
}

void findMin(int sum, int cnt, int S)
{
	if (cnt < S)
	{
		for (int i = 0; i < remote.size(); ++i)
		{
			if (S > 1 && sum == 0 && remote[i] == 0)
				continue;

			int temp = sum * 10 + remote[i];
			findMin(temp, cnt + 1, S);
		}
	}
	else
	{
		if (Min > abs(ch - sum) + S)
		{
			cout << S << "자리, " << sum << "\n";
			Min = abs(ch - sum) + S;
		}
	}
}

int main()
{
	input();

	for(int i = 6; i >= 1; --i)
		findMin(0, 0, i);

	cout << Min << "\n";
	return 0;
}

////0
////9
////1 2 3 4 5 6 7 8 9
////
////== > 1
////
////
////10
////9
////1 2 3 4 5 6 7 8 9
////
////== > 11