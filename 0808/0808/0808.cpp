// 0808.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
bool visited[101][101];
int n;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };

void dfs(int r, int c, int h) {
	if (r >= n || c >= n || r < 0 || c < 0) {
		return;
	}

	if (visited[r][c] || arr[r][c]) {
		return;
	}

	visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		dfs(nr, nc, h);
	}
}

int main()
{
	int minv = 0, maxv = 987654321;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			minv = min(minv, arr[i][j]);
			maxv = max(maxv, arr[i][j]);
		}
	}
	 
	int ans = 1;
	int cnt = 0;

	for (int i = minv; i < maxv; i++) {
		cnt = 0;
		for (int j = 0; j < 100; j++) fill_n(visited[j], 100, false);

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (!visited[y][x] && arr[y][x] > i) {
					dfs(x, y, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans << "\n";

    return 0;
}

