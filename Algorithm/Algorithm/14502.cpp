#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int board[8][8];
int temp[8][8];
int n, m;
int ans = 0;

void bfs() {
	queue<pair<int, int>>q;

	int afterWall[8][8];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			afterWall[i][j] = temp[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (afterWall[i][j] == 2)
				q.push(make_pair(i, j));

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < n&&nc >= 0 && nc < m) {
				if (afterWall[nr][nc] == 0) {
					afterWall[nr][nc] = 2;
					q.push(make_pair(nr, nc));
				}
			}
		}
	}

	int blank=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (afterWall[i][j] == 0) {
				blank++;
			}
		}
	}
	ans = max(ans, blank);
}

void dfs(int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				temp[i][j] = 1;
				dfs(cnt + 1);
				temp[i][j] = 0;
			}	
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						temp[i][j] = board[i][j];
					}
				}
				temp[i][j] = 1;
				dfs(1);
				temp[i][j] = 0;
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}