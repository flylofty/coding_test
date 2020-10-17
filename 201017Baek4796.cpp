#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L = 1;
	int P = 1;
	int V = 1;
	int c = 1;

	while (1)
	{
		cin >> L >> P >> V;

		if (L == P && P == V)
			break;

		int share = V / P;
		int remainder = V % P;

		int answer = L * share;

		if (remainder > L)
			remainder = L;

		answer += remainder;
		cout << "Case " << c++ << ": " << answer << "\n";
	}
	return 0;
}