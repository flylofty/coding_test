#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 0;
char v[64][64]{ NULL };
string answer;

void input()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> v[i][j];
		}
	}
}

string findAnswer(int x1, int x2, int y1, int y2)
{
	if (x2 - x1 == 1 && y2 - y1 == 1)
	{
		if (v[x1][y1] == '0')
			return "0";
		else
			return "1";
	}

	vector<string> temp(4);
	temp[0]= findAnswer(x1, (x2 + x1) / 2, y1, (y2 + y1) / 2); // 좌상
	temp[1] = findAnswer(x1, (x2 + x1) / 2, (y2 + y1) / 2, y2); // 우상
	temp[2] = findAnswer((x2 + x1) / 2, x2, y1, (y2 + y1) / 2); // 좌하
	temp[3] = findAnswer((x2 + x1) / 2, x2, (y2 + y1) / 2, y2); // 우하

	int zero = 0;
	int one = 0;
	string s;
	for (int i = 0; i < 4; ++i)
	{
		s += temp[i];
		if (temp[i] == "0")
			zero++;
		else if (temp[i] == "1")
			one++;
	}

	if (zero == 4 && one == 0)
		s = "0";
	else if (zero == 0 && one == 4)
		s = "1";
	else
		s = "(" + s + ")";

	return s;
}

int main()
{
	input();
	cout << findAnswer(0, N, 0, N) << "\n";
	return 0;
}