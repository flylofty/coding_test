#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int K = 0;
int L = 0;
vector<pair<string, int>> list;

void findAnswer() // 내가 작성한 코드
{
	map<string, int> m;
	cin >> K >> L;
	string temp;
	for (int i = 0; i < L; ++i)
	{
		cin >> temp;
		auto it = m.find(temp);

		if (it == m.end())
		{
			m[temp] = 1;
		}
		else
		{
			m[temp]++;
		}
		list.push_back({ temp, m[temp] });
	}

	int cnt = 0;
	int index = 0;
	while (cnt != K && index != list.size())
	{
		int a = list[index].second;
		int b = m[list[index].first];
		if (a == b)
		{
			cnt++;
			cout << list[index].first << "\n";
		}
		index++;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	findAnswer();
	return 0;
}

////#include <iostream>
////#include <vector>
////#include <algorithm>
////#include <string>
////#include <unordered_map>
////
////using namespace std;
////
////int main() { // 다른 사람이 작성한 코드!!!!
////	ios::sync_with_stdio(false); cin.tie(0);
////	int n, k;
////	string s;
////	unordered_map<string, int> m;
////	vector<pair<int, string>> ar;
////
////	cin >> n >> k;
////
////	for (int i = 0; i < k; i++) {
////		cin >> s;
////		m[s] = i;
////	}
////
////	for (auto i : m) {
////		ar.push_back({ i.second,i.first });
////	}
////	sort(ar.begin(), ar.end());
////
////	n = ar.size() < n ? ar.size() : n;
////	for (int i = 0; i < n; i++) {
////		cout << ar[i].second << '\n';
////	}
////
////	return 0;
////}