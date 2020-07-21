#include <iostream>
#include <string>
#include <vector>

using namespace std;
//프로그래머스 탐욕법 > 체육복
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	int dir[2]{ -1, 1 };

	vector<bool> gymSuit(n + 2, true);
	for (int i = 0; i < lost.size(); ++i) {
		gymSuit[lost[i]] = false;
	}

	vector<bool> oneMore(n + 2, false);
	for (int i = 0; i < reserve.size(); ++i) {
		if (gymSuit[reserve[i]]) {
			oneMore[reserve[i]] = true;
		}
		else {
			gymSuit[reserve[i]] = true;
			answer++;
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		if (!gymSuit[i]) {
			for (int j = 0; j < 2; ++j) {
				int k = i + dir[j];
				if (oneMore[k]) {
					oneMore[k] = false;
					answer++;
					break;
				}
			}
		}
	}

	return answer;
}

int main() {

	//int n = 5;
	//vector<int> lost{2,4};
	//vector<int> reserve{1,3,5};

	//int n = 5;
	//vector<int> lost{ 2,4 };
	//vector<int> reserve{ 3 };

	int n = 3;
	vector<int> lost{ 3 };
	vector<int> reserve{ 1 };

	cout << solution(n, lost, reserve) << endl;

	return 0;
}