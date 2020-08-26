#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N = 0;
//답이 될 수 있는 조건 하나를 찾지 못해서 틀렸음...
int main() {

	cin >> N;

	string a;
	cin >> a;
	vector<int> A(26, 0);
	for (int i = 0; i < a.size(); ++i) {
		A[a[i] - 'A']++;
	}

	int cnt = 0;
	string b;
	vector<int> B;
	for (int i = 0; i < N - 1; ++i) {
		cin >> b;
		B.resize(26, 0);
		for (int j = 0; j < b.size(); ++j) {
			B[b[j] - 'A']++;
		}

		int aSize = a.size();
		int bSize = b.size();

		vector<int> C = A;
		for (int j = 0; j < 26; ++j) {
			if (C[j] == 0 && B[j] == 0) continue;

			if (C[j] == B[j]) {
				aSize -= C[j];
				bSize -= B[j];
				C[j] = 0;
				B[j] = 0;
			}

			else if (C[j] > B[j]) {
				aSize -= B[j];
				C[j] -= B[j];
				bSize -= B[j];
				B[j] = 0;
			}

			else { // C[j] < B[j]
				bSize -= C[j];
				B[j] -= C[j];
				aSize -= C[j];
				C[j] = 0;
			}

		}

		//for (int j = 0; j < 26; ++j)
		//	cout << C[j] << " ";
		//cout << "    " << aSize << endl;
		//for (int j = 0; j < 26; ++j)
		//	cout << B[j] << " ";
		//cout << "    " << bSize << endl;

		if (aSize <= 1 && bSize <= 1) cnt++;

		/*if (aSize == 0 && bSize == 1) cnt++;
		else if (aSize == 1 && bSize == 0) cnt++;
		else if (aSize == 0 && bSize == 0) cnt++;
		else if (aSize == 1 && bSize == 1) cnt++;*/
		B.clear();
	}
	cout << cnt << endl;
	return 0;
}