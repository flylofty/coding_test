#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> q;
	int N = 0;
	cin >> N;
	int num = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> num;
			q.push(num);
			if (q.size() > N)
				q.pop();
		}
	}
	cout << q.top() << "\n";
	return 0;
}