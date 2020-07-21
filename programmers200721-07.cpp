#include <iostream>
#include <string>

using namespace std;
//프로그래머스 연습문제 > 문자열 p와 y의 개수
bool solution(string s) {

	bool answer = true;

	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'p' || s[i] == 'P') cnt++;
		else if (s[i] == 'y' || s[i] == 'Y') cnt--;
	}

	if (cnt != 0)
		answer = false;

	return answer;
}

int main() {
	
	/*string s = "pPoooyY";*/
	string s = "Pyy";

	if (solution(s))
		cout << "개수가 같습니다." << endl;
	else
		cout << "개수가 같지 않습니다." << endl;
	

	return 0;
}