#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 > 두 정수 사이의 합.
long long solution(int a, int b) {
	long long answer = 0;

	int min, max;

	if (a <= b) {
		max = b;
		min = a;
	}
	else {
		max = a;
		min = b;
	}

	for (int i = min; i <= max; ++i) {
		answer += i;
	}
	return answer;
}

int main() {
	int a{3}, b{5};
	cout << solution(a, b) << endl;;
	return 0;
}