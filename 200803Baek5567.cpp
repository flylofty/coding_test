#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int n = 0;
int m = 0;


int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;

	vector<set<int>> friends(n + 1);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		friends[a].insert(b);
		friends[b].insert(a);
	}

	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if (friends[i].count(1)) {
			cnt++;
			continue;
		}
		else {
			for (set<int>::iterator it = friends[i].begin(); it != friends[i].end(); ++it) {
				if (friends[*it].count(1)) {
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}