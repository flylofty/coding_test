#include <iostream>
#include <map>
#include <string>
#include <set>
#include<sstream>
#include <vector>
#include <deque>

using namespace std;

int N = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;
	vector<string> start;
	vector<int> s;

	for (int i = 1; i <= N; ++i) {
		string temp;
		cin >> temp;
		start.push_back(temp);
		s.push_back(i);
	}
	vector<int> end;
	for (int i = 1; i <= N; ++i) {
		string temp;
		cin >> temp;
		int j;
		for (j = 0; j < start.size(); ++j) {
			if (start[j] == temp) break;
		}
		end.push_back(j + 1);
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (end[i] > end[j]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}