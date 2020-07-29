#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int N = 0, M = 0; // 듣도 못한 사람의 수, 보도 못한 사람의 수
set<string> unHeard;

void input() {

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;
		unHeard.insert(name);
	}
}

void findAnswer() {

	vector<string> answer;

	for (int i = 0; i < M; ++i) {
		string name;
		cin >> name;

		if (unHeard.count(name)) answer.push_back(name);
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << "\n";
}

int main() {

	input();
	findAnswer();

	return 0;
}