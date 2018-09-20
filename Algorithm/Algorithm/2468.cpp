#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int a[100][100];
int visited[100][100];
int n;
int cnt = 0;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int h) {
	if (x >= n || y >= n || x < 0 || y < 0)
		return;

	if (visited[y][x] || a[y][x] <= h)
		return;

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		dfs(nx, ny, h);
	}
}

int main(void) {
	int minvalue = 987654321, maxvalue = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &a[i][j]);
			minvalue = min(minvalue, a[i][j]);
			maxvalue = max(maxvalue, a[i][j]);
		}
	}

	int ans = 1;
	for (int i = minvalue; i < maxvalue; i++) {
		cnt = 0;
		for (int j = 0; j < 100; j++) fill_n(visited[j], 100, false);

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (!visited[y][x] && a[y][x] > i) {
					dfs(x, y, i);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}

	printf("%d\n", ans);

	return 0;
}
