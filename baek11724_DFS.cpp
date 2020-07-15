//좋지 않은 코드
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, M; // 정점, 간선의 개수.
vector<vector<int>> adj_matrix(1001, vector<int>(1001, 0));
vector<vector<bool>> isVisited(1001, vector<bool>(1001, false));

void DFS(int start, int end) {
	isVisited[start][end] = isVisited[end][start] = true;

	for (int i = 1; i <= N; ++i) {
		if (!isVisited[end][i] && adj_matrix[end][i]) {
			DFS(end, i);
		}
	}
}

void findAnswer() {
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (!isVisited[i][j] && adj_matrix[i][j]) {
				DFS(i, j);
				//cout << i << " " << j << "\n";
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}

void input() {
	scanf("%d %d", &N, &M);

	vector<int> check(N + 1, 0);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj_matrix[a][b] = adj_matrix[b][a] = 1;
		check[a] = check[b] = 1;
	}

	for (int i = 1; i <= N; ++i) {
		if (check[i] == 0) {
			adj_matrix[i][i] = 1;
		}
	}
}

void printMatrix() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << isVisited[i][j] << " ";
		}
		printf("\n");
	}
}

int main() {

	input();
	findAnswer();
	//printMatrix();

	return 0;
}