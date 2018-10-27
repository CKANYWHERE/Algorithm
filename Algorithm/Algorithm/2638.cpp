#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int arr[102][102];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);

	int day = 0;
	while (1)
	{
		bool inner[102][102] = { true, };
		bool visit[102][102] = { false, };
		int chk[102][102] = { 0, };

		queue<pair<int, int> > q;

		q.push({ 0,0 });

		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;

			q.pop();

			if (visit[y][x])
				continue;

			visit[y][x] = true;
			inner[y][x] = false;

			for (int i = 0; i < 4; i++)
			{
				int hy = dy[i] + y;
				int hx = dx[i] + x;

				if (!((0 <= hy && hy < n) && (0 <= hx && hx < m)))
					continue;

				if (arr[hy][hx] == 1)
					chk[hy][hx]++;

				else if (!visit[hy][hx])
					q.push({ hy,hx });
			}
		}

		bool erase = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (chk[i][j] >= 2)
				{
					arr[i][j] = 0;
					erase = true;
				}
			}

		if (erase)
			day++;
		else
			break;
	}

	printf("%d", day);

	return 0;
}