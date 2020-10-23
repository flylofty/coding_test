#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> check(10000, false);
vector<int> cn;

void makeClockNumber(string arr)
{
	if (arr.size() < 4)
	{
		for (int i = 1; i <= 9; ++i)
		{
			arr.push_back(char('0' + i));
			makeClockNumber(arr);
			arr.pop_back();
		}
	}
	else
	{
		int Min = 10000;
		for (int i = 0; i < 4; ++i)
		{
			int num = 0;
			for (int j = 0; j < 4; ++j)
			{
				num = num * 10 + arr[(j + i) % 4] - '0';
			}

			if (check[num])
				return;

			if (Min > num)
				Min = num;
		}

		if (!check[Min])
		{
			cn.push_back(Min);
			check[Min] = true;
		}
	}
}

int main()
{
	cn.push_back(0);
	makeClockNumber("");
	sort(cn.begin(), cn.end());
	int num = 0;
	for (int i = 0; i < 4; ++i)
	{
		int temp; cin >> temp;
		num = num * 10 + temp;
	}

	string t = to_string(num);

	num = 10000;
	for (int i = 0; i < 4; ++i)
	{
		int temp = 0;
		for (int j = 0; j < 4; ++j)
		{
			temp = temp * 10 + t[(j + i) % 4] - '0';
		}

		if (num > temp)
			num = temp;
	}

	for (int i = 0; i < cn.size(); ++i)
	{
		if (cn[i] == num)
		{
			cout << i << "\n";
			break;
		}
	}

	return 0;
}