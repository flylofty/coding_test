#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	
	vector<string> board;

	int max_size = 0;
	for (int i = 0; i < 5; ++i) {
		string temp; cin >> temp;
		board.push_back(temp);

		if (temp.size() > max_size)
			max_size = temp.size();
	}

	for (int i = 0; i < max_size; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (board[j].size() >= i + 1)
				cout << board[j][i];
		}
	}

	return 0;
}