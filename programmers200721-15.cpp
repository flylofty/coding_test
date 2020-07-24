#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 약수의 합
int solution(int n) {
	int answer = 0;

	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) answer += i;
	}
	return answer;
}

int main() {
	int n = 12;
	cout << solution(n) << endl;
	return 0;
}