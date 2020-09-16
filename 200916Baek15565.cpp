#include <iostream>
#include <vector>

using namespace std;

int main() {

	int N = 0;
	int K = 0;
	cin >> N >> K;

	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		int doll;
		cin >> doll;
		if (doll == 1)
			v.push_back(i);
	}

	if (v.size() < K)
	{
		cout << "-1\n";
		return 0;
	}

	int Min = 1000001;
	int a = v.size() - 1;
	while (a - K + 1 >= 0)
	{
		int b = a - K + 1;
		int len = v[a] - v[b] + 1;

		if (Min > len)
			Min = len;

		a--;
	}

	cout << Min << "\n";
	return 0;
}