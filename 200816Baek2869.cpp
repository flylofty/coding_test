#include <iostream>

using namespace std;

// 1 ≤ B < A ≤ V ≤ 1,000,000,000 이라서 long long type을 사용해야함.
// 1,000,000,000 (10억)을 세 번만 더하면 이미 int형을 벗어남.

int main() {

	long long A, B, V;
	cin >> A >> B >> V;

	long long left = 1, right = V / (A - B);

	if (V % (A - B) != 0)
		right++;

	long long answer; // '='를 빼머리면 틀린 정답이 나올 수 있음. 
	while (left <= right) { // 반례 8 7 27 
		int day = (left + right) / 2;

		if ((day - 1)*(A - B) + A >= V) {
			right = day - 1;
			answer = day;
		}
		else if ((day - 1)*(A - B) + A < V) {
			left = day + 1;
		}
	}

	cout << answer << "\n";

	return 0;
}
//#include <iostream>
//
//using namespace std;
//
//int main() {
//
//	// 완전 탐색으로 풀면 시간초과!!!
//	int A, B, V;
//	cin >> A >> B >> V;
//	int day = 1, snail = 0;
//	while (day) {
//		snail += A;
//		if (snail == V) break;
//		snail -= B;
//		if (snail == V) break;
//		day++;
//	}
//	cout << day << "\n";
//
//	return 0;
//}