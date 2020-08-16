#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int> &A, int num) {
	int left = 0;
	int right = A.size() - 1;

	while (left <= right) {
		int index = (left + right) / 2; // index ==> 배열 인덱스.

		if (A[index] > num) {
			right = index - 1;
		}
		else if (A[index] < num) {
			left = index + 1;
		}
		else
			return true;
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false); // 선언하지 않으면
	cin.tie(NULL), cout.tie(NULL); // 시간초과 남.

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int num; cin >> num;
		if (binarySearch(A, num)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}