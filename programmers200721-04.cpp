#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 프로그래머스 연습문제 > 나누어 떨어지는 숫자 배열
vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] % divisor == 0) {
			answer.push_back(arr[i]);
		}
	}

	if (answer.empty()) {
		answer.push_back(-1);
	}
	else {
		sort(answer.begin(), answer.end());
	}

	return answer;
}

int main() {

	vector<int> arr{ 5,9,7,10 };
	int divisor = 5;

	vector<int> answer = solution(arr, divisor);
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << " ";
	}cout << endl;
	return 0;
}