#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//프로그래머스 코딩테스트 연습 > 해시 > 완주하지 못한 선수
string solution(vector<string> participant, vector<string> completion) {//한 명의 선수를 찾아야함.
	string answer = "";

	//참고함ㅎㅎ string이라도 그냥 sort가 됨ㅎㅎ
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < participant.size(); ++i) {
		bool isExist = false;
		for (int j = i; j < completion.size(); ++j) {
			if (participant[i] == completion[j]) {
				//string temp = completion[j];
				//completion[j] = completion[completion.size() - 1];
				//completion[completion.size() - 1] = temp;
				//completion.resize(completion.size() - 1);
				isExist = true;
				break;
			}
		}
		if (!isExist) {
			return participant[i];
		}
	}

	return answer;
}

int main() {
	//vector<string> participant{"leo", "kiki", "eden"};
	//vector<string> completion{ "eden", "kiki" };

	//vector<string> participant{ "marina", "josipa", "nikola", "vinko", "filipa" };
	//vector<string> completion{ "josipa", "filipa", "marina", "nikola" };

	vector<string> participant{ "mislav", "stanko", "mislav", "ana" };
	vector<string> completion{ "stanko", "ana", "mislav" };

	//for (int i = 0; i < completion.size(); ++i) {
	//	cout << i << " " << completion[i] << endl;
	//}cout << endl;

	//cout << completion.size() << endl;
	//string temp = completion[0];
	//completion[0] = completion[completion.size() - 1];
	//completion[completion.size() - 1] = temp;
	//completion.resize(completion.size() - 1);
	//cout << completion.size() << endl;
	//cout << endl;

	//for (int i = 0; i < completion.size(); ++i) {
	//	cout << i << " " << completion[i] << endl;
	//}cout << endl;

	cout << solution(participant, completion) << "\n";
	return 0;
}