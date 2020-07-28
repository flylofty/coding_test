#include <iostream>
#include <vector>

using namespace std;

int N = 0, L = 0; // 신호등의 개수, 도로의 길이
vector<int> load[1001];
int cnt = 0;

int go(int index) {
	cnt++;
	int cycle = cnt % (load[index][0] + load[index][1]);

	if (cycle < load[index][0]) {
		return load[index][0] - cycle;
	}
	else return 0;
}

void findAnswer() {

	for (int i = 1; i <= L; ++i) {

		if (load[i].empty()) cnt++;

		else cnt += go(i);
	}
	cout << cnt << "\n";
}

int main() {

	cin >> N >> L;

	for (int i = 0; i < N; ++i) {
		int D, R, G;// 신호등, 레드 지속, 그린 지속
		cin >> D >> R >> G;
		load[D].push_back(R);
		load[D].push_back(G);
	}

	findAnswer();

	return 0;
}