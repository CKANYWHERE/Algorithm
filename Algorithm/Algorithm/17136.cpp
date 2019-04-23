#include "pch.h"
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int checkcnt[6];
int dab = INF;

void dfs(int d, int x_, int
	y_, int size, vector< vector<int> > map) {
	bool dabcheck = true;
	if (d > dab) return;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1) { dabcheck = false; break; }
		}
		if (!dabcheck) break;
	}
	if (dabcheck) {
		dab = dab > d - 1 ? d - 1 : dab;
		if (dab == -1) dab = 0;
		return;
	}
	for (int i = y_; i < y_ + size; i++) {
		for (int j = x_; j < x_ + size; j++) {
			if (i >= 10 || j >= 10 || map[i][j] == 0) return;
			map[i][j] = 0;
		}
	}
	int x, y;
	bool flag = false;
	for (x = 0; x < 10; x++) {
		for (y = 0; y < 10; y++) {
			if (map[y][x] == 1) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	for (int i = 5; i >= 1; i--) {
		if (checkcnt[i] == 5) continue;
		checkcnt[i]++;
		dfs(d + 1, x, y, i, map);
		checkcnt[i]--;
	}
}

int main(void) {
	std::vector< std::vector<int> > map(10, vector<int>(10, 0));
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
	dfs(0, 0, 0, 0, map);
	if (dab == INF) cout << -1 << endl;
	else cout << dab << endl;
	return 0;
}