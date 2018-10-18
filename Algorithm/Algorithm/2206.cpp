#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MAX = 1000;
typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M;
int graph[MAX][MAX];
int cache[MAX][MAX][2]; //������ 2�� �� �ձ� ����

int BFS(void)
{
	queue < pair<pair<int, int>, int>> q; //y, x, �� �ձ�
	q.push(make_pair(make_pair(0, 0), 1)); //������, �� �ձ� ����
	cache[0][0][1] = 1;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();
	//�����ϸ�
		if (y == N - 1 && x == M - 1)
			return cache[y][x][block]; //�����ϴ� ĭ�� ����
		for (int i = 0; i < 4; i++)
		{
			int nextY = y + moveDir[i].y;
			int nextX = x + moveDir[i].x;
			if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M)
			{
			//���� �ְ�, ���� ���� �� �վ��ٸ�
				if (graph[nextY][nextX] == 1 && block)
				{
					cache[nextY][nextX][block - 1] = cache[y][x][block] + 1;

					q.push(make_pair(make_pair(nextY, nextX), block - 1));
				}
				//���� ���� �湮���� �ʾҴ� ���̶��
				else if (graph[nextY][nextX] == 0 && cache[nextY][nextX][block] == 0)
				{
					cache[nextY][nextX][block] = cache[y][x][block] + 1;

					q.push(make_pair(make_pair(nextY, nextX), block));
				}
			}
		}
	}
	return -1;
}



int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
			graph[i][j] = temp[j] - '0';
	}
	cout << BFS() << endl;
	return 0;
}