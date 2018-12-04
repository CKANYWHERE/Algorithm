#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring> //memset
using namespace std;
const int MAX = 50;

typedef struct
{
	int y, x;
}Dir;
Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int L, W;
string graph[MAX];
int cache[MAX][MAX];

//�������� BFS

int BFS(int y, int x)
{
	memset(cache, 0, sizeof(cache));
	queue<pair<int, int>> q;
	int result = 0;
	q.push(make_pair(y, x));
	cache[y][x] = 1;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveDir[i].y;
			int nextX = curX + moveDir[i].x;
			result = max(result, cache[curY][curX]);
			//���� ���� �ְ�
			if (0 <= nextY && nextY < L && 0 <= nextX && nextX < W)
				//�ߺ����� �ʾҰ� �����̸� ť�� �ִ´�
				if (graph[nextY][nextX] == 'L' && cache[nextY][nextX] == 0)
				{
					q.push(make_pair(nextY, nextX));
					cache[nextY][nextX] = cache[curY][curX] + 1;
				}
		}
	}
	//result�� ĭ ��, ��δ� 1�� �����Ѵ�
	return result - 1;
}

int main(void)
{
	cin >> L >> W;
	for (int i = 0; i < L; i++)
		cin >> graph[i];

	int result = 0;
	//brute force�� ���� ��ġ ��� ã�ƺ���
	for (int i = 0; i < L; i++)
		for (int j = 0; j < W; j++)
			if (graph[i][j] == 'L')
				result = max(result, BFS(i, j));
	cout << result << endl;
	return 0;

}