#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0;
int  recommend = 0;
int student[101]{0}; // 추천 수
bool isIn[101]{ false };
vector<int> candidate; // 모든 사진들은 비어있다.

void findAnswer() {
	cin >> N;
	cin >> recommend;
	for (int i = 0; i < recommend; ++i) {
		int s; cin >> s;
		student[s]++;
		
		if (candidate.size() < N) {
			if (!isIn[s]) {
				candidate.push_back(s);
				isIn[s] = true;
			}
		}
		else {
			if (!isIn[s]) {
				int index = 0;
				int min = student[candidate[0]];
				for (int i = 1; i < N; ++i) {
					if (min > student[candidate[i]]) {
						index = i;
						min = student[candidate[i]];
					}
				}

				isIn[candidate[index]] = false;
				student[candidate[index]] = 0;
				candidate.erase(candidate.begin() + index);
				candidate.push_back(s);
				isIn[s] = true;
			}
		}
	}
	sort(candidate.begin(), candidate.end());
	for (int i = 0; i < N; ++i)
		cout << candidate[i] << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	findAnswer();

	return 0;
}