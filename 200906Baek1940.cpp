#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int N = 0;
	cin >> N;
	vector<int> v(N, 0);

	int M = 0;
	cin >> M;

	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int cnt = 0;
	int a = 0;
	int b = v.size() - 1;

	while (a < b) {

		int sum = v[a] + v[b];

		if (sum == M) {
			a++;
			b--;
			cnt++;
		}
		else if (sum < M) {
			a++;
		}
		else { // sum >
			b--;
		}

	}
	
	cout << cnt << "\n";
	return 0;
}

//5
//7
//2 5 3 8 9
//0