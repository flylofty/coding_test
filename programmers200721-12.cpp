#include <iostream>
#include <string>
#include <vector>

using namespace std;
//프로그래머스 연습문제 > 수박수박수박수박수박수?
string solution(int n) {
	string answer = "";

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			answer += "수";
		}
		else
			answer += "박";
	}

	return answer;
}

int main() {
	int n = 5;
	cout << solution(n) << endl;
	return 0;
}