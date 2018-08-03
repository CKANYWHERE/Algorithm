
#include"stdafx.h"
#include <cstdio>
void solve(int n, int x, int y) {
	if (n == 0) return;
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);
}
int main() {
	int n;
	scanf_s("%d", &n);
	printf("%d\n", (1 << n) - 1);
	solve(n, 1, 3);
	return 0;
}