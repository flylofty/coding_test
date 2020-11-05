#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;

vector<int> findAsnwer(int index)
{
	int sum = 0;
	for (int i = index; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i + 1] == '(')
			{
				vector<int> t = findAsnwer(i + 2);
				sum = sum + ((s[i] - '0') * t[0]);
				i = t[1];
				continue;
			}
			else
				sum++;
		}
		if (s[i] == ')')
		{
			return {sum, i};
		}
	}
	return { sum, 0 };
}

int main()
{
	cin >> s;
	cout << findAsnwer(0)[0] << "\n";
	return 0;
}
////#include <iostream>
////#include <string>
////// 압축해제한 문자열을 구하는 코드
////using namespace std;
////
////string s;
////
////void unZip(int times, int index)
////{
////	string temp = "";
////	int i = index + 2;
////	for (; s[i] != ')'; ++i)
////		temp.push_back(s[i]);
////
////	string ans;
////	for (int j = 0; j < times; ++j)
////		ans += temp;
////
////	string left;
////	for (int k = 0; k < index; ++k)
////		left.push_back(s[k]);
////
////	string right;
////	for (int k = i + 1; k < s.size(); ++k)
////		right.push_back(s[k]);
////
////	s.clear();
////
////	s = left + ans + right;
////}
////
////int main()
////{
////	cin >> s;
////
////	int i = s.size() - 1;
////	for (; i >= 0; --i)
////	{
////		if (s[i] >= '0' && s[i] <= '9')
////		{
////			if (s[i + 1] == '(')
////			{
////				unZip(int(s[i] - '0'), i);
////			}
////		}
////	}
////
////	cout << s << endl;
////	cout << s.size() << "\n";
////
////	return 0;
////}