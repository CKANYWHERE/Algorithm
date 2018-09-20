#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
bool visited[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;

void dfs(int h, int w, int k) {
	
	if (h >= n || w >= n || h < 0 || w < 0)
		return;

	if (visited[h][w] || arr[h][w] <= k)
		return;

	visited[h][w] = true;

	for (int i = 0; i < 4; i++) {
		int nx = h + dx[i];
		int ny = w + dy[i];

		dfs(nx, ny, i);
	}
	
}

int main() {
	int maxV = 0;
	int minV = 100;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			maxV = max(maxV, arr[i][j]);
			minV = min(minV, arr[i][j]);
		}
	}

	int cnt;
	int ans = 1;
	for (int i = minV; i < maxV; i++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visited[j][k] && arr[j][k] > i) {
					dfs(j, k, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}