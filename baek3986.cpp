#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main() {

	int N;
	scanf("%d", &N);

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		char st[100001];
		scanf("%s", st);

		stack<char> s;
		int st_len = strlen(st);
		for (int j = 0; j < st_len; ++j) {

			if (s.empty() || s.top() != st[j]) {
				s.push(st[j]);
				continue;
			}

			s.pop();
		}

		if (s.empty()) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <stack>
// #include <string>

// using namespace std;

// int main() {

// 	int N;
// 	scanf("%d", &N);

// 	int cnt = 0;
// 	for (int i = 0; i < N; ++i) {
// 		string st;
// 		//scanf("%s", st);
// 		cin >> st;

// 		stack<char> s;
// 		for (int j = 0; j < st.size(); ++j) {

// 			if (s.empty() || s.top() != st[j]) {
// 				s.push(st[j]);
// 				continue;
// 			}

// 			s.pop();
// 		}

// 		if (s.empty()) {
// 			cnt++;
// 		}
// 	}

// 	printf("%d", cnt);

// 	return 0;
// }