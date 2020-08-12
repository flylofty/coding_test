#include <iostream>

using namespace std;

int main() {

	int n = 0;
	cin >> n;

	int cnt = 0;

	int s = 1;
	while (s*s <= n) {
		int temp = s;
		while (temp * s <= n) {
			cnt++;
			temp++;
		}
		s++;
	}
	cout << cnt << "\n";
	return 0;
}