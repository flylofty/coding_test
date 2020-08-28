#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N = 0;
	cin >> N;
	map<string, bool> m;

	string e{ "enter" };
	string l{ "leave" };

	for (int i = 0; i < N; ++i) {
		string name, logg;
		cin >> name >> logg;

		auto it = m.find(name);

		if (logg == e) {
			if (it == m.end()) {
				m.insert({ name, true });
			}
			else {
				it->second = true;
			}
		}
		else if (logg == l) {
			if (it == m.end()) {
				m.insert({ name, false });
			}
			else {
				it->second = false;
			}
		}
	}

	for (map<string, bool>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
	{
		if (it->second)
			cout << it->first << "\n";
	}

	return 0;
}