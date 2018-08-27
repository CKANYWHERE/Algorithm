#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[29][29];
int n, ans;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
double P[4];

double dfs(int r, int c, int n) {
	if (n == 0) return 1.0;

	visited[r][c] = true;
	double result = 0.0;

	for (int i = 0; i < 4; i++) {
		int nc = c + dy[i];
		int nr = r + dx[i];

		if (visited[nr][nc]) continue;
		result += P[i] * dfs(nr, nc, n - 1);

	}
	visited[r][c] = false;
	return result;

}

int main() {
	cin >> n;

	for (int i = 0; i < 4; i++) {
		int p = 0;
		cin >> P[i];
		p = P[i];
		P[i] = p / 100.0;
	}

	printf("%.10lf\n", dfs(14, 14, n));

	return 0;
}