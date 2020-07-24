#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 > 자연수 뒤집어 배열로 만들기.
vector<int> solution(long long n) {
	
	long long num = n;
	vector<int> answer;

	while (num > 0) {
		answer.push_back(num % 10);
		num = num / 10;
	}

	return answer;
}

int main() {
	long long n = 12345;
	vector<int> answer = solution(n);
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << "\n";
	return 0;
}