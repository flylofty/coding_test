#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>

using namespace std;

int n = 0;
int k = 0;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	cin >> k;
	vector<int> cards(n);
	for (int i = 0; i < n; ++i) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());

	unordered_set<string> s;
	string a;
	do {
		a.clear();
		for (int i = 0; i < k; ++i) {
			a += to_string(cards[i]);
		}
		s.insert(a);
	} while (next_permutation(cards.begin(), cards.end()));

	for (auto it = s.begin(); it != s.end(); ++it)
		cout << *it << endl;

	cout << s.size() << "\n";

	return 0;
}

////DFS로 경우의 수를 찾음
////#include <iostream>
////#include <unordered_set>
////#include <vector>
////#include <string>
////
////using namespace std;
////
////int n, k;
////unordered_set<string> us;
////vector<int> v;
////vector<int> visited;
////void fun(string sum, int counter) {
////	if (counter != k) {
////		for (int i = 0; i < n; i++) {
////			if (visited[i] == 0) {
////				visited[i] = 1;
////				fun(sum + to_string(v[i]), counter + 1);
////				visited[i] = 0;
////			}
////		}
////	}
////	else {
////		us.insert(sum);
////	}
////}
////
////int main() {
////
////	cin >> n >> k;
////	v.assign(n, 0);
////	visited.assign(n, 0);
////
////
////	for (int i = 0; i < n; i++) {
////		cin >> v[i];
////	}
////	fun("", 0);
////	cout << us.size() << "\n";
////
////	for (auto &it : us) {
////		cout << it << "   ";
////	}
////	cout << endl;
////
////	return 0;
////}