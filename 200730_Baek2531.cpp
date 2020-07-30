#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N = 0, d = 0, k = 0, c = 0; // 접시 수, 가지 수, 연속, 쿠폰 번호
vector<int> rv;
vector<int> plate;

void input() {
	cin >> N >> d >> k >> c;
	rv.resize(N);
	plate.resize(d + 1, 0);
	for (int i = 0; i < N; ++i) cin >> rv[i];
}

void findAnswer() {

	int cnt = 0;
	int Max = 0;
	set<int> s;

	for (int i = 0; i < k; ++i) {
		if (plate[rv[i]] == 0) {
			cnt++;
		}
		plate[rv[i]]++;
	}

	Max = cnt;
	if (plate[c] == 0) Max++;

	for (int i = k; i < N + k; ++i) {

		int tempCnt = cnt;

		plate[rv[(i - k) % N]]--;
		if (plate[rv[(i - k) % N]] == 0) {
			tempCnt--;
		}

		if (plate[rv[i % N]] == 0) {
			tempCnt++;
		}
		plate[rv[i % N]]++;

		if (plate[c] == 0) {
			Max = max(Max, tempCnt + 1);
		}
		else {
			Max = max(Max, tempCnt);
		}

		cnt = tempCnt;
	}

	cout << Max << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	findAnswer();

	return 0;
}