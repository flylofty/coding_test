#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 0;

bool sumOfDigits(int num) {
	int temp = num;
	int sum = 0;
	while (temp > 0) {
		int a = temp % 10;
		sum += a;
		temp = temp / 10;
	}

	if (num % sum == 0)
		return true;
	else
		return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (sumOfDigits(i))
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}