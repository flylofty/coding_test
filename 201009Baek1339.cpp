#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	vector<string> s;
	vector<int> alpha(26, 0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string temp; cin >> temp;
		s.push_back(temp);
	}

	for (int i = 0; i < N; ++i)
	{
		int increase = 1;
		for (int j = s[i].size() - 1; j >= 0; --j)
		{
			alpha[s[i][j] - 'A'] += increase;
			increase *= 10;
		}
	}

	sort(alpha.begin(), alpha.end(), greater<int>());

	int sum = 0;
	int decrease = 9;
	for (int i = 0; i < 26; ++i)
	{
		sum = sum + alpha[i] * decrease;
		decrease--;
	}

	cout << sum << endl;

	return 0;
}

// 부루트포스... 시간 초과...
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
// 
//using namespace std;
//
//int N = 0;
//vector<string> s;
//int chSize = 0;
//map<char, int> m;
//int Max = 0;
//
//void input()
//{
//	cin >> N; 
//	string temp;
//
//	vector<bool> alpha(26, false);
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> temp;
//		getchar();
//		s.push_back(temp);
//		for (int j = 0; j < s[i].size(); ++j)
//		{
//			if (!alpha[s[i][j] - 'A'])
//			{
//				alpha[s[i][j] - 'A'] = true;
//				chSize++;
//			}
//		}
//	}
//
//	int index = 0;
//	for (int i = 0; i < 26; ++i)
//	{
//		if (alpha[i])
//		{
//			m.insert({'A' + i, index++});
//		}
//	}
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 1; j < N; ++j)
//		{
//			if (s[j].size() > s[j - 1].size())
//			{
//				temp = s[j];
//				s[j] = s[j - 1];
//				s[j - 1] = temp;
//			}
//		}
//	}
//}
//
//void makeNumber(vector<int> v, vector<bool> used)
//{
//	if (v.size() < chSize)
//	{
//		for (int i = 9; i >= 0; --i)
//		{
//			if (v.empty() && i == 0)
//				continue;
//
//			if (used[i])
//				continue;
//
//			used[i] = true;
//			v.push_back(i);
//			makeNumber(v, used);
//			v.pop_back();
//			used[i] = false;
//		}
//	}
//	else
//	{
//		vector<int> aaa;
//		int sum = 0;
//		for (int i = 0; i < s.size(); ++i)
//		{
//			int tSum = 0;
//			for (int j = 0; j < s[i].size(); ++j)
//			{
//				tSum = tSum * 10 + v[m[s[i][j]]];
//			}
//			aaa.push_back(tSum);
//			sum += tSum;
//		}
//
//		if (Max < sum)
//			Max = sum;
//
//		int sss = 0;
//		for (int i = 0; i < aaa.size(); ++i)
//		{
//			//cout << aaa[i] << " ";
//			sss += aaa[i];
//		}
//		//cout << sss << endl; cout << endl;
//	}
//}
//
//int main()
//{
//	input();
//	vector<int> v;
//	vector<bool> used(10, false);
//	makeNumber(v, used);
//	cout << Max << "\n";
//	return 0;
//}