#include <iostream>
#include <vector>
#include <iostream>

using namespace std;
// 프로그래머스 연습문제 > 같은 숫자는 싫어
vector<int> solution(vector<int> arr) {
	vector<int> answer;

	answer.push_back(arr[0]);

	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i] == arr[i - 1]) {
			continue;
		}
		answer.push_back(arr[i]);
	}

	return answer;
}

int main() {

	//vector<int> arr{1,1,3,3,0,1,1};
	vector<int> arr{ 4,4,4,3,3 };

	vector<int> print = solution(arr);

	for (int i = 0; i < print.size(); ++i) {
		cout << print[i] << " ";
	}

	return 0;
}