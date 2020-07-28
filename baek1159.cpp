#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	int N = 0;
	cin >> N;
	vector<int> al(26, 0);

	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;
		int index = name[0] - 'a';
		al[index]++;
	}

	bool flag = false;
	for (int i = 0; i < 26; ++i) {
		if (al[i] >= 5) {
			char ch = 'a' + i;
			cout << ch;
			flag = true;
		}
	}

	if (!flag)
		cout << "PREDAJA";

	return 0;
}