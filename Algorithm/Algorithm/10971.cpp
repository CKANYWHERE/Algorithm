#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[20][20];
int n;
bool check[15];
int minValue = 987654321;
int start;

void dfs(int x, int cnt, int sum) {
	if (cnt == n && start == x) {
		minValue = min(minValue, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		if (arr[x][i] == 0) continue;
		if (sum + arr[x][i] > minValue) continue;
		check[i] = true;
		dfs(i, cnt + 1, sum + arr[x][i]);
		check[i] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		start = i;
		dfs(i, 0, 0);
	}

	cout << minValue << "\n";
	return 0;
}