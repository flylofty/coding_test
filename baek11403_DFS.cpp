#include <iostream>
#include <cstdio>

using namespace std;

//정점의 개수.
int N = 0;

//인접행렬
int adj_matrix[101][101]{ 0 };
int isVisited[101][101]{ 0 };

void printAnswer() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%d ", adj_matrix[i][j]);
		}
		printf("\n");
	}
}

void DFS(int start, int end) {

	adj_matrix[start][end] = 1;
	isVisited[start][end] = 1;

	for (int i = 1; i <= N; ++i) {

		if (adj_matrix[end][i] && isVisited[start][i] == 0) {

			DFS(start, i);
		}
	}
}

void findAnswer() {

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (adj_matrix[i][j] == 1 && isVisited[i][j] == 0) {
				DFS(i, j);
			}
		}
	}
}

void input() {

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &adj_matrix[i][j]);
		}
	}
}

int main() {

	input();
	findAnswer();
	printAnswer();
	return 0;
}