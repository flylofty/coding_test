#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n = 0;
	cin >> n;

	int  cnt = 0;
	int title = 666;
	while (1) {
		string temp = to_string(title);
        // 이것보다 차라리
        //// ex) a = 66611,  a % 1000 == 666, a = a / 10;
        // 1000으로 나눴을 때 나머지가 666인 것을 찾기가 더 나음~! (지렷다!!!ㅋㅋㅋ)
		for (int i = 0; i <= temp.size() - 3; ++i) {
			if (temp[i] == '6' && temp[i + 1] == '6' && temp[i + 2] == '6') {
				cnt++;
				break;
			}
		}

		if (cnt == n) {
			cout << title << "\n";
			break;
		}

		title++;
	}

	return 0;
}