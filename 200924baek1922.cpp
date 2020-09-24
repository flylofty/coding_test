#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<pair<int, pair<int, int>>> nodes;
vector<int> sack;

void input() {

	cin >> N; // 정점의 개수
	sack.resize(N + 1, 0);
	for (int i = 1; i <= N; ++i) sack[i] = i;

	cin >> M; // 간선의 개수
	for (int i = 0; i < M; ++i) { // 간선리스트 입력
		pair<int, pair<int, int>> temp;
		cin >> temp.second.first >> temp.second.second >> temp.first;
		nodes.push_back(temp);
	}

	sort(nodes.begin(), nodes.end());

	cout << "\n";
	for (int i = 0; i < nodes.size(); ++i) {
		cout << nodes[i].second.first << " " << nodes[i].second.second << " " << nodes[i].first << "\n";
	}
}

int find(int a) {
	if (sack[a] == a) return a;
	else return sack[a] = find(sack[a]);
}

bool isSamePack(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return true;

	// union or merge시 무식하게 반복문 돌려도 이 코드와 시간이 같이 나옴.
	sack[b] = a;

	return false;
}

void findAnswer() {

	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < nodes.size(); ++i) {

		int n1 = nodes[i].second.first;
		int n2 = nodes[i].second.second;

		if (!isSamePack(n1, n2)) {
			sum += nodes[i].first;
			cnt++;
		}

		if (cnt == N - 1) break;

	}
	cout << sum << "\n";
}

void printParent() {
	for (int i = 1; i <= N; ++i)
		cout << sack[i] << " ";
	cout << "\n";
}

int main() {

	input();
	findAnswer();
	printParent();

	return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int N = 0, M = 0;
// vector<pair<int, pair<int, int>>> nodes;
// int con[1001][1001]{0};
// vector<bool> isVisited;

// void input() {

// 	cin.tie(0);
// 	cin >> N;
// 	cin >> M;

// 	for (int i = 0; i < M; ++i) {
// 		int n1, n2, cost;
// 		pair<int, pair<int, int>> temp;
// 		cin >> temp.second.first >> temp.second.second >> temp.first;
// 		nodes.push_back(temp);
// 	}
// 	isVisited.resize(N + 1, false);
// 	sort(nodes.begin(), nodes.end());
// }

// bool isConnected(int s, int e) {

// 	isVisited[s] = true;

// 	if (s == e) return true;

// 	for (int i = 1; i <= N; ++i) {
// 		if (con[s][i] && !isVisited[i]) {
// 			bool temp = isConnected(i, e);
// 			if (temp) return true;
// 		}
// 	}

// 	return false;
// }

// void turnFalse() {
// 	for (int i = 1; i <= N; ++i)
// 		isVisited[i] = false;
// }

// void findAnswer() {
// 	int sum = 0;
// 	int cnt = 0;
// 	for (int i = 0; i < nodes.size(); ++i) {

// 		int s = nodes[i].second.first;
// 		int e = nodes[i].second.second;
// 		int v = nodes[i].first;
// 		turnFalse();

// 		if (!isConnected(s, e)) {
// 			sum += v;
// 			cnt++;
// 			con[s][e] = con[e][s] = 1;
// 		}

// 		if (cnt == N - 1) break;

// 	}
// 	cout << sum << "\n";
// }

// int main() {

// 	input();
// 	findAnswer();

// 	return 0;
// }