#include <iostream>

using namespace std;
//프로그래머스 연습문제 > 자릿수 더하기.
int solution(int n)
{
	int num = n;
	int answer = 0;

	while (num > 0) {
		answer += num % 10;
		num /= 10;
	}

	return answer;
}

int main() {
	int n = 987;
	cout << solution(n) << "\n";
	return 0;
}