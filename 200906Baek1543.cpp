#include <iostream>
#include <string>

using namespace std;

int main() {

	string a;
	getline(cin, a);

	string b;
	getline(cin, b);

	int cnt = 0;
	
	if (a.size() >= b.size()) {
		for (int i = 0; i < a.size() - b.size() + 1; ++i) {
			if (b[0] == a[i]) {
				int j = 1;
				int k = i + 1;
				for (; j < b.size(); ++j, ++k) {
					if (b[j] != a[k]) break;
				}
				if (j == b.size()) {
					cnt++;
					i = k - 1;
				}
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}