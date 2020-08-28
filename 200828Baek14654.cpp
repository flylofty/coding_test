#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isWin(int x, int y) {

	if (x == 1 && y == 3) return true;
	else if (x == 2 && y == 1) return true;
	else if (x == 3 && y == 2) return true;
	
	return false;
}

int main() {

	int N = 0;
	cin >> N;

	vector<int> a(N);
	vector<int> b(N);

	for (int i = 0; i < N; ++i)
		cin >> a[i];

	for (int i = 0; i < N; ++i)
		cin >> b[i];

	int aWin = 0;
	int bWin = 0;
	int Max = 0;

	for (int i = 0; i < N; ++i) {
		
		if (a[i] != b[i]) {
			if (isWin(a[i], b[i])) {
				aWin++;
				bWin = 0;
			}
			else {
				bWin++;
				aWin = 0;
			}
		}
		else { // 비긴경우
			if (aWin > 0) {
				aWin = 0;
				bWin++;
			}
			else {
				bWin = 0;
				aWin++;
			}
		}

		int temp = max(aWin, bWin);
		if (Max < temp)
			Max = temp;
	}
	cout << Max << "\n";
	return 0;
}