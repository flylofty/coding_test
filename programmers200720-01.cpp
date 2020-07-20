#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 프로그래머스 크레인 인형뽑기 게임.
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	stack<int> basket;

	for (int i = 0; i < moves.size(); ++i) {

		int crane = moves[i] - 1;

		int doll = 0;
		for (int j = 0; j < board.size(); ++j) {

			if (board[j][crane] == 0)
				continue;
			else {
				doll = board[j][crane];
				board[j][crane] = 0;
				break;
			}
		}

		if (doll == 0)
			continue;

		if (basket.empty() || basket.top() != doll) {
			basket.push(doll);
			continue;
		}

		basket.pop();
		answer += 2;

	}

	return answer;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//                         //1  2  3  4  5
	//vector<vector<int>> board{{0, 0, 0, 0, 0},  //0
	//                          {0, 0, 1, 0, 3},  //1
	//                          {0, 2, 5, 0, 1},  //2
	//						  {4, 2, 4, 4, 2},  //3
	//						  {3, 5, 1, 3, 1}}; //4
								 //1  2  3  4  5
	vector<vector<int>> board{{0, 0, 0, 0, 0},  //0
							  {0, 0, 0, 0, 0},  //1
							  {0, 0, 0, 0, 0},  //2
							  {0, 0, 0, 0, 0},  //3
							  {0, 0, 0, 0, 0} }; //4

	vector<int> moves{ 1, 5, 3, 5, 1, 2, 1, 4 };

	cout << solution(board, moves) << "\n";
	return 0;
}