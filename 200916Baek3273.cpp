#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n = 0;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int x = 0;
	cin >> x;

	int cnt = 0;
	int a = 0;
	int b = n - 1;

	while (a < b)
	{
		if (v[a] + v[b] == x)
		{
			cnt++;
			a++;
			b--;
		}
		else if (v[a] + v[b] < x)
		{
			a++;
		}
		else
		{
			b--;
		}
	}

	cout << cnt << endl;

	return 0;
}