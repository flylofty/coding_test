#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 프로그래머스 연습문제 > 문자열 내 마음대로 정렬하기
vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	vector<string> temp[26];

	for (unsigned int i = 0; i < strings.size(); ++i) {
		char ch = strings[i][n];
		temp[ch - 'a'].push_back(strings[i]);
	}

	for (unsigned int i = 0; i < 26; ++i) {
		if (temp[i].empty()) {
			continue;
		}
		else {
			sort(temp[i].begin(), temp[i].end());

			for (unsigned int j = 0; j < temp[i].size(); ++j) {
				answer.push_back(temp[i][j]);
			}
		}
	}

	return answer;
}
//vector<string> solution(vector<string> strings, int n) {
//	vector<string> answer = strings;
//
//	for (unsigned int i = 0; i < answer.size(); ++i) {
//		char temp = answer[i][n];
//		answer[i][n] = answer[i][0];
//		answer[i][0] = temp;
//	}
//
//	sort(answer.begin(), answer.end());
//
//	for (unsigned int i = 0; i < answer.size(); ++i) {
//		char temp = answer[i][n];
//		answer[i][n] = answer[i][0];
//		answer[i][0] = temp;
//	}
//
//	return answer;
//}

int main() {

	//vector<string> strings{ "sun", "bed", "car" };
	//int n = 1;

	vector<string> strings{ "abce", "abcd", "cdx" };
	int n = 2;

	vector<string> answer = solution(strings, n);
	for (unsigned int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << endl;
	}
	return 0;
}