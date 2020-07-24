#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 프로그래머스 연습문제 > 정수 내림차순으로 배치하기
long long solution(long long n) {

	long long num = n;
	vector<int> answer;

	while (num > 0) {
		answer.push_back(num % 10);
		num = num / 10;
	}
	sort(answer.begin(), answer.end(), greater<int>());

	for (int i = 0; i < answer.size(); ++i) {
		num += answer[i];
		num = num * 10;
	}
	num = num / 10;

	return num;
}

int main() {
	long long n = 118372;
	cout << solution(n) << "\n";
	return 0;
}