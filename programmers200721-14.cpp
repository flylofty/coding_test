#include <iostream>
#include <string>
#include <vector>

using namespace std;
//프로그래머스 연습문제 시저 암호
string solution(string s, int n) {
	string answer = "";

	int numOfalphabet = 26;
	vector<char> alphabet{ 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	for (int i = 0; i < s.size(); ++i) {

		char ch = s[i];

		if (s[i] >= 'a' && s[i] <= 'z') {
			int index = (s[i] + n - 'a') % numOfalphabet;
			ch = alphabet[index];
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			int index = (s[i] + n - 'A') % numOfalphabet;
			ch = alphabet[index] - 32;
		}

		answer.push_back(ch);
	}

	return answer;
}

int main() {
	string s{"a B z"};
	int n{4};
	cout << solution(s, n) << endl;
	return 0;
}