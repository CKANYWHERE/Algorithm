#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int max_value = 0;
char arr[51][51];
bool visited[51][51];
int len[61][61];

void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	while (!q.empty())
	{
		int root_r = q.front().first;
		int root_c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = root_r + dx[i];
			int nc = root_c + dy[i];
			if (arr[nr][nc] == 'L' && visited[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
				visited[nr][nc] = true;
				len[nr][nc] = len[root_r][root_c] + 1;
				if (max_value < len[nr][nc])
					max_value = len[nr][nc];
			}
		}
	}
}

int main() {

	int h, w; //y,xÁÂÇ¥
	cin >> h >> w;


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			cout << arr[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 'L' && visited[i][j] == false) {
				bfs(i, j);
				memset(visited, 0, sizeof(visited));
				memset(len, 0, sizeof(len));
			}
		}
	}

	cout << max_value << "\n";
	return 0;
}