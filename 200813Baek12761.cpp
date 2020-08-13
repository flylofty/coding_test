#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int A, B;
int N, M;
bool bridge[100001]{false};

void BFS() {
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	bridge[N] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int n_cnt = q.front().second;
		q.pop();

		if (now == M) {
			cout << n_cnt << "\n";
			return;
		}

		// +1 만큼 이동
		if (now + 1 <= M && !bridge[now + 1]) {
			q.push(make_pair(now + 1, n_cnt + 1));
			bridge[now + 1] = true;
		}

		// -1 만큼 이동
		if (now - 1 >= 0 && !bridge[now - 1]) {
			q.push(make_pair(now - 1, n_cnt + 1));
			bridge[now - 1] = true;
		}

		// +A 만큼 이동
		if (now + A <= M && !bridge[now + A]) {
			q.push(make_pair(now + A, n_cnt + 1));
			bridge[now + A] = true;
		}

		// -A 만큼 이동
		if (now - A >= 0 && !bridge[now - A]) {
			q.push(make_pair(now - A, n_cnt + 1));
			bridge[now - A] = true;
		}

		// *A 만큼 이동
		if (now*A <= M && !bridge[now * A]) {
			q.push(make_pair(now * A, n_cnt + 1));
			bridge[now * A] = true;
		}

		// +B 만큼 이동
		if (now + B <= M && !bridge[now + B]) {
			q.push(make_pair(now + B, n_cnt + 1));
			bridge[now + B] = true;
		}

		// -B 만큼 이동
		if (now - B >= 0 && !bridge[now - B]) {
			q.push(make_pair(now - B, n_cnt + 1));
			bridge[now - B] = true;
		}

		// *B 만큼 이동
		if (now * B <= M && !bridge[now * B]) {
			q.push(make_pair(now * B, n_cnt + 1));
			bridge[now * B] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> A >> B >> N >> M;
	BFS();
	return 0;
}