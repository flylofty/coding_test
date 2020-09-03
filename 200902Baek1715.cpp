#include <iostream>
#include <queue>

using namespace std;

int N = 0;
priority_queue<int, vector<int>, greater<int>> q;

int main() {

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int num = 0;
		cin >> num;
		q.push(num);
	}

	int sum = 0;
	while (q.size() > 1) {
		int cnt = 0;
		int temp = 0;
		while (!q.empty()) {
			temp += q.top();
			q.pop();
			cnt++;
			if (cnt == 2) break;
		}
		q.push(temp);
		sum += temp;
	}
	cout << sum << "\n";
	return 0;
}