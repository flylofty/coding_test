#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int K = 0;
vector<int> bucket(1000001, 0);
long w = 0;
long long Max = 0;
int m_Index = 0;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;

	w = 2 * K + 1;

	for (int i = 0; i < N; ++i) {
		int g, x; cin >> g >> x;
		bucket[x] = g;
		Max += g;

		if (m_Index < x)
			m_Index = x;
	}

	if (w > m_Index) {
		cout << Max << "\n";
		return 0;
	}
	else {
		Max = 0;
	}

	for (int i = 0; i < w; ++i) {
		Max += bucket[i];
	}

	long long temp = Max;
	for (int i = w; i < m_Index + 1; ++i) {
		temp += bucket[i] - bucket[i - w];
		if (temp > Max)
			Max = temp;
	}

	cout << Max << "\n";

	return 0;
}