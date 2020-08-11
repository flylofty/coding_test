#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int R, C;
char puzzle[20][20];
vector<string> answer;

void findAnswer() {
	cin >> R >> C;

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> puzzle[i][j];
		}
	}

	for (int i = 0; i < R; ++i) { 
		string temp;
		for (int j = 0; j < C; ++j) { // 왼쪽 -> 오른쪽
			char ch = puzzle[i][j];

			if (ch == '#') {
				if (temp.size() >= 2) 
					answer.push_back(temp);
				temp.clear();
				continue;
			}
			temp.push_back(ch);
		}
		if (temp.size() >= 2)
			answer.push_back(temp);
	}

	for (int i = 0; i < C; ++i) {
		string temp;
		for (int j = 0; j < R; ++j) { // 위 -> 아래
			char ch = puzzle[j][i];
			if (ch == '#') {
				if (temp.size() >= 2)
					answer.push_back(temp);
				temp.clear();
				continue;
			}
			temp.push_back(ch);
		}
		if (temp.size() >= 2)
			answer.push_back(temp);
	}

	sort(answer.begin(), answer.end());
	cout << answer[0] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	findAnswer();
	return 0;
}