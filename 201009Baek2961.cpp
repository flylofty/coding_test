#include <iostream>
#include <vector>

using namespace std;

int N = 0;
vector<int> S;
vector<int> B;

vector<long> X;
vector<long> Y;

int Min = 987654321;

void findCase(int pre, int C1, int C2)
{
	for (int i = pre + 1; i < N; ++i)
	{
		X.push_back(S[i] * C1);
		Y.push_back(B[i] + C2);
		findCase(i, S[i] * C1, B[i] + C2);
	}
}

int main()
{
	cin >> N;
	S.assign(N, 0);
	B.assign(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i] >> B[i];
	}
	findCase(-1, 1, 0);
	for (int i = 0; i < X.size(); ++i)
	{
		if (Min > abs(X[i] - Y[i]))
			Min = abs(X[i] - Y[i]);
		// cout << X[i] << " " << Y[i] << "  차이" << abs(Y[i] - X[i]) << "\n";
	}
	//cout << endl << endl;

	//for (int i = 0; i < X.size(); ++i)
	//{
	//	for (int j = 0; j < Y.size(); ++j)
	//	{
	//		if (abs(X[i] - Y[j]) < Min && abs(X[i] - Y[j]) > 0)
	//			Min = abs(X[i] - Y[j]);
	//	}
	//}
	cout << Min << "\n";
	return 0;
}