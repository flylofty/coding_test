#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
vector<long long> v;

void dfs(long long sum, int pre) {
	v.push_back(sum);
	for (int i = pre - 1; i >= 0; --i) {
		if (pre > i)
		{
			dfs(sum*10 + i, i);
		}
	}
}

int main() {

	cin >> N;

	v.push_back(0);
	for (int i = 1; i <= 9; ++i) {
		dfs(i, i);
	}
	
    // 1022 번째 수 == 9876543210
    // v vector의 사이즈는 1023
	if (v.size() - 1 >= N)
	{
		sort(v.begin(), v.end());
		cout << v[N] << endl;
	}
	else 
	{
		cout << "-1\n";
	}

	return 0;
}