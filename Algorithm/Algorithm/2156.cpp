#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int dp[10001];
int main() {
	int n;
	int temp1, temp2, temp3;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		temp1 = temp2 = temp3 = 0;
		temp1 = dp[i - 1];
		temp2 = dp[i - 2] + a[i];
		temp3 = dp[i - 3] + a[i - 1] + a[i];
		dp[i] = max(temp1, max(temp2, temp3));
	}
	cout << dp[n] << "\n";
	return 0;
}