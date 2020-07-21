#include <iostream>
#include <string>
#include <math.h>

using namespace std;
// 프로그래머스 연습문제 > 문자열을 정수로 바꾸기
int solution(string s) {
	int answer = 0;

	int position = s.size();
	int i = 0;
	int sign = 1;
	if (s[0] == '-') {
		sign = -1;
		position--;
		i++;
	}
	else if (s[0] == '+') {
		position--;
		i++;
	}
	position = pow(10, position - 1);
	for (i; i < s.size(); ++i) {
		int num = (s[i] - '0') * position;
		answer += num;
		position /= 10;
	}

	return answer * sign;
}

int main() {

	string s = "+1234";
	cout << solution(s) << endl;
	return 0;
}