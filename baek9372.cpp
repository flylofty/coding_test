#include <iostream>

using namespace std;

int main() {

	int T = 0;
	cin >> T;

	int N = 0, M = 0;// 국가의 수, 비행기의 종류

	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < M; ++i) {
			int n1, n2;
			cin >> n1 >> n2;
		}
		cout << N - 1 << endl;
	}

	return 0;
}

//https://jaimemin.tistory.com/715 참고함.