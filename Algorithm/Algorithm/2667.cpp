#include "pch.h"
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[30][30];
int dist[30][30];
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans[25*25];

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	dist[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (arr[nx][ny] == 1 && dist[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && dist[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[dist[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt +1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}