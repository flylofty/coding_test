#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	cin >> N;

	stack<pair<int, int>> s;
	vector<int> v(N + 1);

	int top;

	for (int i = 1; i <= N; ++i) {
		cin >> top;

		while (!s.empty()) {

			if (s.top().first <= top) {
				s.pop();
			} 
			else {
				v[i] = s.top().second;
				break;
			}
		}

		if (s.empty()) {
			v[i] = 0;
		}

		s.push(pair<int, int>(top, i));
	}

	for (int i = 1; i <= N; ++i)
		cout << v[i] << " ";

	return 0;
}