#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 > 서울에서 김서방 찾기
string solution(vector<string> seoul) {
	string answer = "김서방은 ";
	string Kim = "Kim";

	for (int i = 0; i < seoul.size(); ++i) {
		if (seoul[i] == Kim) {
			string positon = to_string(i);
			answer += ( positon + "에 있다");
			break;
		}
	}

	return answer;
}

int main() {
	vector<string> seoul{ "Jane", "Kim" };
	cout << solution(seoul) << endl;
	return 0;
}