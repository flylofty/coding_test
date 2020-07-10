#include <iostream>
#include <vector>

using namespace std;

int k = 6;
vector< vector<int> > adj_matrix(14, vector<int>(14, 0));

void DFS(int index, vector<int> v) {

	v.push_back(index);

	if (v.size() == 6) {
		for (int i = 0; i < 6; ++i) {
			cout << adj_matrix[v[i]][0] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= k; ++i) {
		if (adj_matrix[index][i] == 1) {
			DFS(i, v);
		}
	}
}

void input() {

	adj_matrix.resize(14, vector<int>(14, 0));

	for (int i = 1; i <= k; ++i) { //오름차 순으로 주어진다.
		cin >> adj_matrix[i][0];

		int more = 6 - i;
		for (int j = i + 1; j <= k; ++j) {

			if (more > k - j + 1)
				break;
			
			adj_matrix[i][j] = 1;
		}
	}

}

int main() {

	vector<int> v;

	while (1) {

		cin >> k;

		if (k == 0) break;

		input();

		for (int i = 1; i <= k; ++i) {
			if (k - i + 1 >= 6) {
				DFS(i, v);
			}
		}
		cout << endl;
	}

	return 0;
}