#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; //행, 렬
vector<vector<int>> box;
queue<pair<int, int>> mature;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void input() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	box.resize(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				mature.push(pair<int, int>(i, j));
			}
		}
	}
}

void BFS() {
	while (!mature.empty()) {
		int cur_x = mature.front().first;
		int cur_y = mature.front().second;
		mature.pop();
		for (int i = 0; i < 4; ++i) {
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];
			if ((next_x >= 1 && next_x <= N) && (next_y >= 1 && next_y <= M) && box[next_x][next_y] == 0) {
				box[next_x][next_y] = box[cur_x][cur_y] + 1;
				mature.push(pair<int, int>(next_x, next_y));
			}
		}
	}
}

void findAnswer() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int Max = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (Max < box[i][j]) Max = box[i][j];
			if (box[i][j] == 0) {
				cout << "-1\n";
				return;
			}
		}
	}
	cout << Max - 1 << "\n";
}

int main() {
	input();
	BFS();
	findAnswer();
	return 0;
}
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cstdio>

// using namespace std;

// int N, M; //행, 렬
// vector<vector<int>> box;
// queue<pair<int, int>> mature;
// int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
// int notMature = 0;
// int Max = 0;

// void input() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);

// 	cin >> M >> N;
// 	box.resize(N + 1, vector<int>(M + 1));
// 	for (int i = 1; i <= N; ++i) {
// 		for (int j = 1; j <= M; ++j) {
// 			cin >> box[i][j];

// 			if (box[i][j] == 0) {
// 				notMature++;
// 			}
// 			else if (box[i][j] == 1) {
// 				mature.push(pair<int, int>(i, j));
// 			}
// 		}
// 	}
// }

// void BFS() {

// 	bool isIn = false;

// 	while (!mature.empty()) {
// 		int cur_x = mature.front().first;
// 		int cur_y = mature.front().second;
// 		mature.pop();

// 		for (int i = 0; i < 4; ++i) {
// 			int next_x = cur_x + dir[i][0];
// 			int next_y = cur_y + dir[i][1];

// 			if ((next_x >= 1 && next_x <= N) && (next_y >= 1 && next_y <= M) && box[next_x][next_y] == 0) {
// 				notMature--;
// 				box[next_x][next_y] = box[cur_x][cur_y] + 1;
// 				isIn = true;
// 				Max = box[next_x][next_y];
// 				mature.push(pair<int, int>(next_x, next_y));
// 			}
// 		}
// 	}

// 	if (isIn)
// 		Max--;
// }

// int main() {

// 	input();

// 	BFS();

// 	if (notMature == 0)
// 		cout << Max << "\n";
// 	else
// 		cout << "-1\n";

// 	return 0;
// }
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//int N, M; //행, 렬
//vector<vector<int>> box;
//queue<pair<int, int>> mature;
//queue<pair<int, int>> mature;
//int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
//int notMature = 0;
//
//void input() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> M >> N;
//	box.resize(N + 1, vector<int>(M + 1));
//	for (int i = 1; i <= N; ++i) {
//		for (int j = 1; j <= M; ++j) {
//			cin >> box[i][j];
//
//			if (box[i][j] == 1)
//				mature.push(pair<int, int>(i, j));
//			else if(box[i][j] == 0)
//				notMature++;
//		}
//	}
//}
//
//void BFS() {
//
//	mature = mature;
//
//	while (!mature.empty()) {
//		int cur_x = mature.front().first;
//		int cur_y = mature.front().second;
//		mature.pop();
//		mature.pop();
//
//		for (int i = 0; i < 4; ++i) {
//			int next_x = cur_x + dir[i][0];
//			int next_y = cur_y + dir[i][1];
//
//			if ((next_x >= 1 && next_x <= N) && (next_y >= 1 && next_y <= M) && box[next_x][next_y] == 0) {
//				notMature--;
//				box[next_x][next_y] = 1;
//				mature.push(pair<int, int>(next_x, next_y));
//			}
//		}
//	}
//
//}
//
//int main() {
//
//	input();
//
//	int cnt = -1;
//	while (!mature.empty()) {
//		cnt++;
//		BFS();
//	}
//
//	cout.tie(0);
//	if (notMature == 0)
//		cout << cnt << "\n";
//	else
//		cout << "-1\n";
//
//	return 0;
//}