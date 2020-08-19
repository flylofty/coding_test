#include <iostream>
#include <string>

typedef struct {
	int x, y;
}position;

using namespace std;

position k, s;

string king{ NULL };
string stone{ NULL };
int N;
int dir[4][2]{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 위, 오른, 아래, 왼

int main() {

	cin >> king >> stone >> N;

	k.x = 8 - (king[1] - '0');
	k.y = king[0] - 'A';

	s.x = 8 - (stone[1] - '0');;
	s.y = stone[0] - 'A';

	for (int i = 0; i < N; ++i) {
		string move;
		cin >> move;

		int n_x = k.x, n_y = k.y;
		int s_x = s.x, s_y = s.y;
		cout << k.x << "  " << k.y << endl;
		for (int i = 0; i < move.size(); ++i) 
		{
			
			if (move[i] == 'T') // up
			{
				n_x = n_x + dir[0][0];
				n_y = n_y + dir[0][1];
				s_x = s_x + dir[0][0];
				s_y = s_y + dir[0][1];
			}
			else if (move[i] == 'R')
			{
				n_x = n_x + dir[1][0];
				n_y = n_y + dir[1][1];
				s_x = s_x + dir[1][0];
				s_y = s_y + dir[1][1];
			}
			else if (move[i] == 'B')
			{
				n_x = n_x + dir[2][0];
				n_y = n_y + dir[2][1];
				s_x = s_x + dir[2][0];
				s_y = s_y + dir[2][1];
			}
			else if (move[i] == 'L')
			{
				n_x = n_x + dir[3][0];
				n_y = n_y + dir[3][1];
				s_x = s_x + dir[3][0];
				s_y = s_y + dir[3][1];
			}
		}

		if (n_x >= 0 && n_x < 8 && n_y >= 0 && n_y < 8)
		{
			if (n_x == s.x && n_y == s.y) 
			{
				if (s_x >= 0 && s_x < 8 && s_y >= 0 && s_y < 8) 
				{
					s.x = s_x;
					s.y = s_y;
				}
				else 
				{
					continue;
				}
			}
			k.x = n_x;
			k.y = n_y;
		}
	}
	

	king[0] = 'A' + k.y;
	king[1] = 8 - k.x + '0';

	stone[0] = 'A' + s.y;
	stone[1] = 8 - s.x + '0';

	cout << king << "\n" << stone;

	return 0;
}