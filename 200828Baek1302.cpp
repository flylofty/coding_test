#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N = 0;
	cin >> N;

	map<string, int> m;
	for (int i = 0; i < N; ++i) {
		string a{NULL};
		cin >> a;
		auto it = m.find(a);
		if (it == m.end()) 
		{
			m.insert({ a, 0 });
		}
		else
		{
			it->second++;
		}
	}

	int max = 0;
	vector<string> answer;
	for (auto &it : m) {

		if (max < it.second) {
			answer.clear();
			max = it.second;
			answer.push_back(it.first);
		}
		else if (max == it.second) {
			answer.push_back(it.first);
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer[0] << "\n";

	return 0;
}