#include <iostream>
#include <map>
#include <string>
#include <set>
#include<sstream>
#include <vector>
#include <deque>

using namespace std;

int N;

int find(int num) {

	int temp;
	int c = 0;
	while (num > 0) {
		temp = num % 10;
		num = num / 10;
		if (temp!= 0 && temp % 3 == 0) c++;
	}
	return c;
}

int main() {

	cin >> N;

	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		int su = find(i);
		if (su > 0) {
			cout << i << "\n";
			cnt += su;
		}
	}
	cout << cnt << "\n";
	return 0;
}