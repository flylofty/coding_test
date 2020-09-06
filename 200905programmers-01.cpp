#include <iostream>
#include <string>
#include <vector>

// 1. 90도 회전
// 2. 완전탐색

// KAKAO BLIND RECRUITMENT 자물쇠와 열쇠
using namespace std;

int lockSize;
int keySize;
int d;
int tempCnt = 0;

bool isFit(vector<vector<int>> key, vector<vector<int>> lock, int x, int y) {
	tempCnt++;
	for (int i = 0; i < keySize; ++i) {
		for (int j = 0; j < keySize; ++j) {
			// cout << i + x << "  " << j + y << "  ";
			if (i + x >= 0 && i + x < lockSize && j + y >= 0 && j + y < lockSize)
			{
				lock[i + x][j + y] += key[i][j];
			}
		}
		//cout << endl;
	}
	//cout << endl;

	int cnt = 0;
	for (int i = 0; i < lockSize; ++i) {
		for (int j = 0; j < lockSize; ++j) {
			if (lock[i][j] == 1) cnt++;
			//cout << lock[i][j] << " ";
		}
		//cout << endl;
	}

	if (cnt == lockSize * lockSize) return true;
	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	d = key.size() - 1;
	lockSize = lock.size();
	keySize = key.size();

	for (int a = 0; a < 4; ++a) {

		for (int i = -d; i < lockSize; ++i) {
			for (int j = -d; j < lockSize; ++j) {
				if (isFit(key, lock, i, j)) return true;
			}
		}

		if (a != 3) { // 오른쪽 90도 회전
			vector<vector<int>> temp(keySize, vector<int>(keySize, 0));
			for (int i = 0; i < key.size(); ++i) {
				for (int j = 0; j < key.size(); ++j) {
					temp[i][j] = key[key.size() - j - 1][i];
				}
			}
			key = temp;
		}
	}

	return false;
}

int main() {

	vector<vector<int>> key{ {0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
	vector<vector<int>> lock{ {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
	cout << solution(key, lock) << endl;
	return 0;
}