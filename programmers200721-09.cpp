#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 문자열 다루기 기본
bool solution(string s) {
	bool answer = true;
	int size = s.size();

	if (!(size == 4 || size == 6))
		return false;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			continue;
		}
		else {
			return false;
		}
	}

	return answer;
}

int main() {
	//string s = "a234";
	string s = "1";
	if (solution(s))
		cout << "참" << endl;
	else
		cout << "거짓" << endl;

	return 0;
}