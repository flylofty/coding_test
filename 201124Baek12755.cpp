#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	int digit = 1;
	int a = 1, b = 9;
	int x = 1, y = (b - a + 1) * digit;

	while (1)
	{
		if (x <= N && N <= y)
		{
			break;
		}
		a *= 10;
		b = b * 10 + 9;
		digit++;
		x = y + 1;
		y = (b - a + 1) * digit + (x - 1);
	}

	int first = ((N - x) / digit) * digit + x;
	string w = to_string(((N - x) / digit) + a);

	cout << w[N - first] << "\n";

	return 0;
}

//#include <iostream>
//#include <math.h>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int N = 0;
//	cin >> N;
//
//	int digit = 1;
//	int x = 1, y = 9;
//
//	while (1)
//	{
//		if (x <= N && N <= y)
//			break;
//		digit++;
//		x = y + 1;
//		y = (pow(10, digit) - pow(10, digit -1)) * digit + (x - 1);
//	}
//
//	int first = ((N - x) / digit) * digit + x;
//	string w = to_string(((N - x) / digit) + pow(10, digit - 1));
//
//	cout << w[N - first] << "\n";
//
//	return 0;
//}
//
////#include <iostream>
////#include <math.h>
////
////using namespace std;
////
////int main()
////{
////	int N = 0;
////	cin >> N;
////
////	int digit = 1;
////	int x = 1, y = 9;
////
////	while (1)
////	{
////		if (x <= N && N <= y)
////			break;
////		digit++;
////		x = y + 1;
////		y = ( pow(10, digit) - pow(10, digit - 1) ) * digit + (x - 1);
////	}
////
////	int first = pow(10, digit - 1);
////	int number = (N - x) / digit + first;
////	int index = ( (N - x) / digit ) * digit + x;
////
////	for (int i = 0; i < digit; ++i)
////	{
////		if (index + i == N)
////		{
////			cout << number / first << "\n";
////			break;
////		}
////		else
////		{
////			number = number % first;
////			first = first / 10;
////		}
////	}
////
////	return 0;
////}
////
//////#include <iostream>
//////#include <string>
//////
//////using namespace std;
//////
//////int main() 
//////{
//////	int N = 0;
//////	cin >> N;
//////
//////	int number = 1;
//////	int cnt = 1;
//////
//////	while (1)
//////	{
//////		string temp = to_string(number++);
//////
//////		if (cnt <= N && N < cnt + temp.size())
//////		{
//////			cout << temp[N - cnt] << "\n";
//////			return 0;
//////		}
//////		else
//////		{
//////			cnt += temp.size();
//////		}
//////	}
//////	return 0;
//////}