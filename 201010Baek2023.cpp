#include <iostream>
#include <string>

using namespace std;

int N = 0;

//bool isDecimal(int num)
//{
//	if (num == 0 || num == 1)
//		return false;
//
//	for (int i = 2; i < num; ++i)
//	{
//		if (num % i == 0)
//			return false;
//	}
//
//	return true;
//}

// 다른 코드 참고함.
bool primeNum(int n)
{
	if (n == 1) return false;

	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0) return false;
	}

	return true;
}

void findAnswer(string sum)
{
	if (sum.size() < N)
	{
		string temp;
		for (int i = 0; i < 10; ++i)
		{
			temp.clear();
			temp = sum;
			temp += to_string(i);
			int num = stoi(temp);

			if (primeNum(num))
			{
				findAnswer(temp);
			}
		}
	}
	else
	{
		cout << sum << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	string sum[4]{"2","3","5","7"};
	for (int i = 0; i < 4; ++i)
	{
		findAnswer(sum[i]);
	}
	return 0;
}