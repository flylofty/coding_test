#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
int m = 0;
int p = 0;
int l = 0;

vector<int> v[100];
vector<int> answer;

int input(int index) {
	v[index].assign(p, 0);
	for (int i = 0; i < p; ++i) {
		cin >> v[index][i];
	}
	sort(v[index].begin(), v[index].end(), greater<int>());

	int temp = 1;
	if (p > l) {
		temp = v[index][l - 1];
	}

	return temp;
}

int main() {

	cin >> n >> m;
	
	for (int i = 0; i < n; ++i) {
		cin >> p >> l;
		answer.push_back(input(i));
	}

	sort(answer.begin(), answer.end());

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (m - answer[i] >= 0) {
			m = m - answer[i];
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}