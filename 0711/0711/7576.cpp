#include "stdafx.h"
#include <cstdio>
#include <queue>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int tomato[100][100];
bool check[100][100];
int main() {
	int n, m;
	queue<pair<int, int>> q;	
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d",&tomato[i][j]);
			if (tomato[i][j] == 1) {
				q.push(make_pair(i,j));
				check[i][j] = true;
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < c) {
				if (tomato[nr][nc] == 0 && check[nr][nc] == false) {
					q.push(make_pair(nr,nc));
					tomato[nr][nc] = tomato[r][c] + 1;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans < tomato[i][j]) {
				ans = tomato[i][j];
			}
		}
	}   

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<m; j++) {
			if (check[i][j] == true && tomato[i][j] == -1) {
				ans = -1;
			}
		}
	}

	printf("%d \n",ans);

	return 0;
}