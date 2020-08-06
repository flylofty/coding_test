#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, K;
string line[2];

void bfs() {

	pair<pair<int, int>, int> p(pair<int, int>(0, 0), -1);
	line[0][0] = '0';
	queue<pair<pair<int, int>, int>> q;
	q.push(p);

	while (!q.empty()) {
		int x = q.front().first.first; //0과 1만 올 수 있음!!!
		int y = q.front().first.second;
		int e = q.front().second;
		/*line[x][y] = '0';*/
		q.pop();

		if (y + 1 >= N || y + K >= N) {
			//cout << line[0] << endl;
			//cout << line[1] << endl;
			cout << "1\n";
			return;
		}

		if (y + 1 < N && line[x][y + 1] == '1') {
			pair<pair<int, int>, int> p(pair<int, int>(x, y+1), e + 1);
			line[x][y + 1] = '0';
			q.push(p);
		}
		if (y - 1 >= 0 && y - 1 > e + 1 && line[x][y - 1] == '1') {
			pair<pair<int, int>, int> p(pair<int, int>(x, y - 1), e + 1);
			line[x][y - 1] = '0';
			q.push(p);
		}
		if (x == 0) {
			if (y + K < N && line[1][y + K] == '1') {
				pair<pair<int, int>, int> p(pair<int, int>(1, y + K), e + 1);
				line[1][y + K] = '0';
				q.push(p);
			}
		}
		if (x == 1) {
			if (y + K < N && line[0][y + K] == '1') {
				pair<pair<int, int>, int> p(pair<int, int>(0, y + K), e + 1);
				line[0][y + K] = '0';
				q.push(p);
			}
		}

	}

	//cout << line[0] << endl;
	//cout << line[1] << endl;
	cout << "0\n";
}

// 백준 15558 점프게임.
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;
	cin >> line[0];
	cin >> line[1];
	bfs();

	return 0;
}