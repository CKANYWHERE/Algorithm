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
	if (h >= n || w >= n && h || h < 0 || w < 0)
		return;
	if (visited[h][w] || arr[h][w]<k)
		return;
	visited[h][w] = true;

	for (int i = 0; i < 4; i++) {
		int nh = h + dx[i];
		int nw = w + dy[i];
		dfs(nh, nw, k);
	}
}

int main() {
	cin >> n;
	int cnt=0, ans=0;
	int minvalue = 987654321, maxvalue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			minvalue = min(minvalue, arr[i][j]);
			maxvalue = max(maxvalue, arr[i][j]);
		}
	}

	for (int k = minvalue; k < maxvalue; k++) {
		cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && arr[i][j] > k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}