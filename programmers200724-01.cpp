#include <iostream>
#include <string>
#include <vector>

using namespace std;
//프로그래머스 연습문제 > 이상한 문자 만들기.
char change(char s, char ch, char e, int sum) {

	if (s <= ch && ch <= e)
		return ch;

	return ch + sum;
}

string solution(string s) {
	string answer = s;

	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {

		if (answer[i] == ' ') {
			cnt = 0;
			continue;
		}

		if (cnt % 2 == 0) {
			answer[i] = change('A', answer[i], 'Z', -32);
			cnt++;
		}
		else {
			answer[i] = change('a', answer[i], 'z', +32);
			cnt++;
		}
	}

	return answer;
}

int main() {
	string s = "try hello world";
	cout << solution(s) << "\n";
	return 0;
}