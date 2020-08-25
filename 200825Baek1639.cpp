#include <iostream>
#include <string>

using namespace std;

string S;
// 1639 행운의 티켓
bool isLucky(int Len) {
	
	int len = Len / 2;
	int left = 0;
	int right = 0;

	for (int i = 0; i < len; ++i) {
		left += S[i] - '0';
	}

	for (int i = len; i < Len; ++i) {
		right += S[i] - '0';
	}

	if (left == right)
		return true;

	for (int i = Len; i < S.size(); ++i) {
		right -= S[i - len] - '0';
		right += S[i] - '0';
		left -= S[i - Len] - '0';
		left += S[i - len] - '0';

		if (left == right)
			return true;
	}

	return false;
}

int main() {

	cin >> S;
	int len = S.size();

	if (len % 2 != 0) len--;

	int i;
	for (i = len; i >= 2; i = i - 2) {
		if (isLucky(i)) break;
	}
	cout << i << endl;
	return 0;
}