#include <iostream>
#include <stack>
#include <string>

using namespace std;
string bar;

int numOfbar() {
	stack<char> s;
	int cnt = 0;

	for (int i = 0; i < bar.size(); ++i) {

		if (bar[i] == '(') {
			if (i + 1 < bar.size()) {
				if (bar[i + 1] == ')') { //레이저
					i++;
					cnt += s.size();
					continue;
				}
				else {
					s.push(bar[i]);
				}
			}
		}
		else { // 막대기의 끝
			cnt++;
			s.pop();
		}
	}

	return cnt;
}

int main() {

	cin >> bar;
	cout << numOfbar();
	return 0;
}