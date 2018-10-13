#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1])) + arr[i][j];
		}
	}

	cout << dp[n][m] << "\n";
	return 0;
}
