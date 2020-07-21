#include <iostream>
#include <vector>

using namespace std;
// 프로그래머스 연습문제 > 소수 찾기
int solution(int n) {
	int answer = 0;

	vector<bool> check(n + 1, false);

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; i*j <= n; ++j) {
			if (!check[i*j]) {
				check[i*j] = true;
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		if (!check[i]) answer++;
	}

	return answer;
}

//int solution(int n) {
//	int answer = 0;
//
//	for (int i = 2; i <= n; ++i) {
//		bool flag = false;
//		for (int j = 2; j < i; ++j) {
//			if (i % j == 0) {
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) {
//			answer++;
//		}
//	}
//
//	return answer;
//}

int main() {
	int n = 10;
	cout << solution(n) << endl;
	return 0;
}