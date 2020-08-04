#include <iostream>
#include <map>
#include <string>
#include <set>
#include<sstream>
#include <vector>
#include <deque>

using namespace std;

int T;
int d_index;

bool isPalindrome(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size() / 2; ++i) {
		if (s[i] != s[s.size() - 1 - i]) {
			d_index = i;
			return false;
		}
	}
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	// 자체로 회문 : 0, 유사 회문 : 1, 그 외: 2
	cin >> T;
	vector<int> answer;

	for (int i = 0; i < T; ++i) {
		string temp;
		cin >> temp;
		bool isD = isPalindrome(temp);
		if (isD) {
			answer.push_back(0);
		}
		else {
			string a1 = temp;
			string a2 = temp;
			a1.erase(d_index, 1);
			a2.erase(a2.size() - 1 - d_index, 1);
			if (isPalindrome(a1) || isPalindrome(a2)) {
				answer.push_back(1);
			}
			else {
				answer.push_back(2);
			}
		}
	}

	for (int i = 0; i < T; ++i)
		cout << answer[i] << "\n";

	return 0;
}