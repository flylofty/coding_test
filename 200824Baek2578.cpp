#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> position(26);
vector<vector<bool>> check(5, vector<bool>(5, false));
vector<vector<int>> board(5, vector<int>(5));
int numOfLine = 0;

bool isIn(int x, int y) {
	if (x >= 0 && x < 5 && y >= 0 && y < 5) return true;
	else {
		return false;
	}
}

bool crossCheck(int x, int y) {
	int rightUp = 0;
	int n_x = x - 1;
	int n_y = y + 1;
	while (isIn(n_x, n_y)) {
		if (check[n_x][n_y]) rightUp++;
		else break;
		n_y++;
		n_x--;
	}

	int leftDown = 0;
	n_x = x + 1;
	n_y = y - 1;
	while (isIn(n_x, n_y)) {
		if (check[n_x][n_y]) leftDown++;
		else break;
		n_y--;
		n_x++;
	}

	if (rightUp + leftDown + 1 == 5) return true;
	else return false;
}

bool widthCheck(int x, int y) {
	int right = 0;
	int n_x = x;
	int n_y = y + 1;
	while (isIn(n_x, n_y)) {
		if (check[n_x][n_y]) right++;
		else break;
		n_y++;
	}

	int left = 0;
	n_x = x;
	n_y = y - 1;
	while (isIn(n_x, n_y)) {
		if (check[n_x][n_y]) left++;
		else break;
		n_y--;
	}

	if (right + left + 1 == 5) return true;
	else return false;
}

bool heightCheck(int x, int y) {
	int up = 0;
	int n_x = x - 1;
	int n_y = y;
	while (isIn(n_x, n_y)) {
		if (check[n_x][n_y]) up++;
		else break;
		n_x--;
	}

	int down = 0;
	n_x = x + 1;
	n_y = y;
	while (isIn(n_x, n_y)) {
		if (check[n_x][n_y]) down++;
		else break;
		n_x++;
	}

	if (up + down + 1 == 5) return true;
	else return false;
}


int main() {

	vector<int> answer;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> board[i][j];
			position[board[i][j]].first = i;
			position[board[i][j]].second = j;
		}
	}

	int call;
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> call;
			int x = position[call].first;
			int y = position[call].second;
			check[x][y] = true;
			cnt++;

			if (crossCheck(x, y)) numOfLine++;
			if (heightCheck(x, y)) numOfLine++;
			if (widthCheck(x, y)) numOfLine++;

			if (numOfLine >= 3) answer.push_back(cnt);
		}
	}

	cout << answer[0] << endl;

	return 0;
}