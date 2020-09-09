#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 2019 KAKAO BLIND RECRUITMENT 길 찾기 게임
typedef struct Tree
{
	int x, v;
	struct Tree* left;
	struct Tree* right;
}tree;

vector<int> a;

void traversal(tree *pre, char op)
{
	if (pre == NULL)
		return;

	if (op == 'b')
	{
		a.push_back(pre->v);
		traversal(pre->left, op);
		traversal(pre->right, op);
	}
	else
	{
		traversal(pre->left, op);
		traversal(pre->right, op);
		a.push_back(pre->v);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer;

	int n = nodeinfo.size();
	vector<pair<int, pair<int, int>>> temp(n);
	for (int i = 0; i < n; ++i)
	{
		temp[i].first = nodeinfo[i][1];
		temp[i].second.first = nodeinfo[i][0];
		temp[i].second.second = i + 1;
	}

	sort(temp.rbegin(), temp.rend());

	tree root;
	root.x = temp[0].second.first;
	root.v = temp[0].second.second;
	root.left = root.right = NULL;

	for (int i = 1; i < n; ++i)
	{
		tree* pre = &root;
		int x = temp[i].second.first; // x좌표
		int node = temp[i].second.second; // 노드번호

		while (1)
		{
			if (pre->x < x)
			{
				if (pre->right == NULL)
				{
					tree* newNode = (tree*)malloc(sizeof(tree));
					newNode->x = x;
					newNode->v = node;
					newNode->left = newNode->right = NULL;
					pre->right = newNode;
					break;
				}
				pre = pre->right;
			}
			else 
			{
				if (pre->left == NULL)
				{
					tree* newNode = (tree*)malloc(sizeof(tree));
					newNode->x = x;
					newNode->v = node;
					newNode->left = newNode->right = NULL;
					pre->left = newNode;
					break;
				}
				pre = pre->left;
			}
		}

	}

	for (int i = 0; i < 2; ++i)
	{
		a.clear();
		char op;
		if (i == 0) op = 'b';
		else op = 'a';
		traversal(&root, op);
		answer.push_back(a);
	}

	return answer;
}

int main() {

	vector<vector<int>> nodeinfo{ {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };
	vector<vector<int>> k = solution(nodeinfo);
	for (int i = 0; i < k.size(); ++i)
	{
		for (int j = 0; j < k[i].size(); ++j)
			cout << k[i][j] << " ";
		cout << endl;
	}
	return 0;
}