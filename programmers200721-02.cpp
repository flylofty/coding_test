#include <iostream>
#include <string>
#include <vector>

using namespace std;
//프로그래머스 연습문제 가운데 글자 가져오기.
string solution(string s) {
	string answer = "";

	int size = s.size();

	if (s.size() % 2 == 0) {
		answer += s[s.size() / 2 - 1];
	}

	answer += s[s.size() / 2];

	return answer;
}

int main() {
	/*string s = "abcde";*/
	string s = "abcdef";

	cout << solution(s) << endl;
	return 0;
}