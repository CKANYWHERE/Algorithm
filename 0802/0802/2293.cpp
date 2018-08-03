#include "stdafx.h"
#include <iostream>
using namespace std;

int a[101];
int dp[10001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++){
			if (j - a[i] >= 0) {
				dp[j] += dp[j - a[i]];
			}
		}
	}
	cout << dp[m] << "\n";
}