#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		int n, k, m; // 1 ~ n번호, k 점프, m처음 치우는 돌 
		cin >> n >> k >> m;

		if (!(n + k + m--)) break;

		vector<int> s;
		for (int i = 0; i < n; ++i) s.push_back(i+1);

		s.erase(s.begin() + (m % n));
		m--;

		while (s.size() != 1){

			m = (m + k) % s.size();
			s.erase(s.begin() + m);
			
			m--;
			if (m < 0) 
				m = s.size() - 1;

		}

		cout << s[0] << "\n";

	}

	return 0;
}