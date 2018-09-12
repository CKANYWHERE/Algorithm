#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

int arr[26][26];
int dist[26][26];
int n;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

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
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && dist[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}