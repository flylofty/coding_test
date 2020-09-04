#include <iostream>

using namespace std;

int main() {

	int n = 0;
	cin >> n;

	int a = 5;
	int b = 2;

	int Min = 999999;
	for (int i = 0; ; ++i) {
		int temp = n;
		if (i * a > temp) break;
		int sum = i;
		temp = temp - (i * a);
		if (temp % b == 1) continue;
		sum += temp / b;
		if (Min > sum)
			Min = sum;
	}
	if (Min == 999999)
		cout << "-1\n";
	else
		cout << Min << "\n";
	return 0;
}