#include <iostream>
#include <string>
#include <vector>

using namespace std;
//프로그래머스 완전탐색 > 모의고사
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt(3, 0);

	vector<int> supo[3]{ {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };

	for (int i = 0; i < answers.size(); ++i) {

		if (supo[0][i % 5] == answers[i]) cnt[0]++;
		if (supo[1][i % 8] == answers[i]) cnt[1]++;
		if (supo[2][i % 10] == answers[i]) cnt[2]++;
	}

	int max = 0;
	for (int i = 0; i < 3; ++i) {
		if (max < cnt[i])
			max = cnt[i];
	}

	for (int i = 0; i < 3; ++i) {
		if (max == cnt[i])
			answer.push_back(i + 1);
	}

	return answer;
}

int main() {

	//vector<int> answers{ 1,2,3,4,5 };
	//vector<int> answers{ 1,3,2,4,2 };
	vector<int> answers{ 1,3,2,4 };

	vector<int> answer = solution(answers);

	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << endl;
	}

	return 0;
}