#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, ans;
bool check[99];
char s[22][22];

void dfs(int r, int c,int a) {

	if (ans < a) ans = a;

	check[s[r][c]] = true;
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i], ny = c + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && (check[s[nx][ny] - 'A'] == 0)) {
			check[s[nx][ny]-'A'] = true;
			dfs(nx, ny, a + 1);
			check[s[nx][ny]-'A'] = false;
		}
			
	}
	
}


int main() {  

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}
	ans = 1;
	check[s[0][0] - 'A'] = true;
	dfs(1, 1, ans);
	cout << ans << "\n";
	return 0;
}