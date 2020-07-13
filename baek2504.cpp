#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<string> st;
	string strings;
	string temp;
	int tempSum;
	int result = 1;
	cin >> strings;
	for (int i = 0; i < strings.size(); i++) {
		temp = strings.at(i);
		if (temp == "(" || temp == "[")
			st.push(temp);
		else {
			tempSum = 1;
			// (1)
			while (!st.empty() && st.top() != "(" && st.top() != "[") {
				//(2)
				tempSum *= stoi(st.top());
				st.pop();
			}
			// (3)
			if (st.empty() || (temp == ")" && st.top() != "(") || (temp == "]"&& st.top() != "[")) {
				result = 0;
				break;
			}
			// (4)
			if (temp == ")")
				tempSum *= 2;
			else
				tempSum *= 3;
			st.pop();
			// (5)
			while (!st.empty() && st.top() != "(" && st.top() != "[") {
				tempSum += stoi(st.top());
				st.pop();
			}
			st.push(to_string(tempSum));
		}
	}
	if (result == 0 || st.size() != 1 || st.top() == "[" || st.top() == "(")
		cout << 0;
	else
		cout << st.top();

	return 0;
}//// https://mountrivers.github.io/BOJ-2504-post/ 참고함...
//#include <iostream>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//stack<string> s;
//
//bool sum(string temp) {
//
//	string end;
//	int value = 0;
//	int mul = 0;
//
//	if (s.top() == "(" || s.top() == "[") {
//		value = 1;
//	}
//
//	if (temp == ")") {
//		end = "(";
//		mul = 2;
//	}
//	else {
//		end = "[";
//		mul = 3;
//	}
//
//	while (end != s.top()) {
//
//		if ((s.top() == "(" && temp == "]") || (s.top() == "[" && temp == ")")) {
//			return false;
//		}
//
//		string t = s.top();
//		value = value + stoi(t);
//		s.pop();
//	}
//
//	s.pop();
//	value = value * mul;
//	s.push(to_string(value));
//	return true;
//}
//
//int main() {
//
//	string arr;
//	string temp;
//	cin >> arr;
//
//	for (int i = 0; i < arr.size(); ++i) {
//
//		temp = arr.at(i);
//		
//		if (temp == "(" || temp == "[") {
//			s.push(temp);
//			continue;
//		}
//
//		if (!sum(temp)) {
//			cout << "0" << endl;
//			return 0;
//		}
//	}
//
//	int answer = 0;
//	while (!s.empty()) {
//		string st = s.top();
//		s.pop();
//
//		if (st == "(" || st == "[") {
//			cout << "0" << endl;
//			return 0;
//		}
//
//		answer += stoi(st);
//	}
//
//	cout << answer << endl;
//
//	return 0;
//}