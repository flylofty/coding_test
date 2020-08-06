#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <queue>

using namespace std;

int findMinimum(string a, string b) {
	int minIndex = 0;
	int min = 51;
	for (int i = 0; i <= b.size() - a.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < a.size(); ++j) {
			if (a[j] != b[j + i]) cnt++;
		}
		if (cnt < min) {
			min = cnt;
			minIndex = i;
		}
	}
	return minIndex;
}

int main() {

	string a, b;
	vector<string> AB;
	getline(cin, a); 
	{
		istringstream s1(a); string stringBuffer;
		while (getline(s1, stringBuffer, ' ')) AB.push_back(stringBuffer);
		a.clear();
	}

	a = AB[0], b = AB[1];

	while (a.size() != b.size()) {
		int minIndex = findMinimum(a, b);

		if (minIndex == 0 && a.size() < b.size()) {//뒤에 넣기.
			int a_size = a.size();
			char ch = b[a_size];
			a.push_back(ch);
		}
		else { // 앞에 넣기.
			string temp = "";
			char ch = b[minIndex-1];
			temp.push_back(ch);
			a = temp + a;
		}
	}

	int cnt = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}