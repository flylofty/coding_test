#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N = 0, P = 0;
	stack<int> s[7];
	int cnt = 0;

	cin >> N >> P;

	for (int i = 0; i < N; ++i) {
		int n, p;
		cin >> n >> p;

		if (s[n].empty()) {
			s[n].push(p);
			cnt++;
			continue;
		}

		if (s[n].top() == p) {
			continue;
		}
		else if (s[n].top() > p) {

			while (!s[n].empty()) {

				if (s[n].top() > p) {
					s[n].pop();
					cnt++;
				}
				else
					break;
			}

			if (s[n].empty()) {
				s[n].push(p);
				cnt++;
			}
			else if (s[n].top() < p) {
				s[n].push(p);
				cnt++;
			}
		}
		else {
			s[n].push(p);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}
//#include <iostream>
//#include <vector> // 의외로 cin cout을 cin.tie(0); cout.tie(0);이걸로 해서 쓰면 빨리 나옴.
//#include <stack>
//
//using namespace std;
//
//int main() {
//
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N = 0, P = 0;
//	stack<int> s[7];
//	int cnt = 0;
//
//	cin >> N >> P;
//	//scanf("%d %d", &N, &P);
//
//	for (int i = 0; i < N; ++i) {
//		int n, p;
//		cin >> n >> p;
//		//scanf("%d %d", &n, &p);
//
//		while (!s[n].empty() && s[n].top() > p) {
//			s[n].pop();
//			cnt++;
//		}
//		if (s[n].empty() || s[n].top() < p) {
//			s[n].push(p);
//			cnt++;
//		}
//
//	}
//
//	//printf("%d\n", cnt);
//	cout << cnt;
//
//	return 0;
//}