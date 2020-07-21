#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 > 문자열 내림차순으로 배치하기
string solution(string s) {
	string answer = "";

	// small letter
	vector<int> sl(26, 0);

	// capital letter
	vector<int> cl(26, 0);

	for (int i = 0; i < s.size(); ++i) {
		if ('a' <= s[i] && s[i] <= 'z') {
			sl[s[i] - 'a']++;
		}
		else if('A' <= s[i] && s[i] <= 'Z') {
			cl[s[i] - 'A']++;
		}
	}

	for (int i = 25; i >= 0; --i) {
		for (int j = 0; j < sl[i]; ++j) {
			answer.push_back(char('a' + i));
		}
	}

	for (int i = 25; i >= 0; --i) {
		for (int j = 0; j < cl[i]; ++j) {
			answer.push_back(char('A' + i));
		}
	}

	return answer;
}

int main() {
	string s = "Zbcdefg";
	cout << solution(s) << endl;
	return 0;
}