#include <iostream>
#include <vector>
#include <queue>
#include <set>

int N{0};
std::vector<bool> fd[50];

void input() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char temp;
			std::cin >> temp;

			if (temp == 'Y')
				fd[i].push_back(true);
			else
				fd[i].push_back(false);
		}
	}
}

int bfs(int node) {
	std::queue<std::pair<int, int>> q;
	std::set<int> s;
	q.push({node, 0});
	while (!q.empty()) {
		int vertex = q.front().first;
		int level = q.front().second;
		q.pop();

		if (level == 2)
			continue;

		for (int i = 0; i < N; ++i) {
			if (fd[vertex][i] && i != node) {
				q.push({ i, level + 1 });
				s.insert(i);
			}
		}
	}
	// std::cout << node << " 's friend\n";
	// for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
	// 	std::cout << *it << " ";
	// }std::cout << std::endl;
	return s.size();
}

void findAnswer() {
	int Max = 0;
	for (int i = 0; i < N; ++i) {
		int f = bfs(i);
		if (Max < f)
			Max = f;
	}
	std::cout << Max << std::endl;
}

int main() {

	input();
	findAnswer();
	return 0;
}