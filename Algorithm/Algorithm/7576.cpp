#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[1001][1001];
int dist[1001][1001];
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int n, m;
int ans = 0;

void bfs(int r, int c) {
	
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
				if (arr[nr][nc] == 0 && dist[nr][nc] == -1) {
					if (arr[nr][nc] == 1) {
						return;
					}
					q.push(make_pair(nr, nc));
					dist[nr][nc] = dist[r][c] + 1;
				}
			}
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dist[i][j] = -1;
			if (arr[i][j] == 1) {
				dist[i][j] = 0;
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j];
		}
		cout << "\n";
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<m; j++) {
			ans = max(ans, dist[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && dist[i][j] == -1) {
				ans = -1;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}