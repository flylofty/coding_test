#include <iostream>
#include <vector>
#include <string>

using namespace std;

int S = 0; //문자열의 길이
int P = 0; // 부분문자열의 길이
string arr{NULL};
vector<int> numOfChar(4, 0);
vector<int> num_s(4, 0);

void input() {
	cin >> S >> P;
	cin >> arr;
	for (int i = 0; i < 4; ++i) {
		cin >> numOfChar[i];
	}
}

bool isArr() {
	for (int i = 0; i < 4; ++i) {
		if (num_s[i] < numOfChar[i])
			return false;
	}
	return true;
}

void findAnswer() {

	int numOfArr = 0;

	for (int i = 0; i < P; ++i) {
		if (arr[i] == 'A') num_s[0]++;
		else if (arr[i] == 'C') num_s[1]++;
		else if (arr[i] == 'G') num_s[2]++;
		else if (arr[i] == 'T') num_s[3]++;
	}

	if (isArr())
		numOfArr++;

	for (int i = P; i < arr.size(); ++i) {
		char ch = arr[i - P];
		if (ch == 'A' && num_s[0] >= 1) num_s[0]--;
		else if (ch == 'C' && num_s[1] >= 1) num_s[1]--;
		else if (ch == 'G'&& num_s[2] >= 1) num_s[2]--;
		else if (ch == 'T'&& num_s[3] >= 1) num_s[3]--;

		ch = arr[i];
		if (ch == 'A') num_s[0]++;
		else if (ch == 'C') num_s[1]++;
		else if (ch == 'G') num_s[2]++;
		else if (ch == 'T') num_s[3]++;

		if (isArr())
			numOfArr++;
	}
	cout << numOfArr << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	input();
	findAnswer();
	return 0;
}