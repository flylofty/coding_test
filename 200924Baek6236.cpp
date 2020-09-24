#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
vector<int> v;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M; // N일, M번 통장에서 K원 인출
	v.assign(N, 0);

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i]; // i번째 날에 이용할 금액
		sum += v[i];
	}

	int a = 0;
	int b = sum;
	int Min = 987654321;

	while (a <= b)
	{
		int mid = (a + b) / 2;

		int K = mid;
		int i = 0;
		int day = 1;
		for (; i < N; ++i)
		{
			if (mid < v[i])
				break;

			if (K < v[i])
			{
				K = mid;
				day++;
			}

			K -= v[i];
		}

		if (day <= M && i == N)
		{
			b = mid - 1;
			Min = mid;
		}
		else
		{
			a = mid + 1;
		}
	}

	cout << Min << endl;

	return 0;
}