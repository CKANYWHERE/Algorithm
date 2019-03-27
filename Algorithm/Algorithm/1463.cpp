#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int main() {
	int n;
	int temp1, temp2, temp3;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		temp1 = temp2 = temp3 = 987654321;
		temp1 = dp[i - 1] + 1;
		if (i % 3 == 0) {
			temp2 = dp[i / 3] + 1;
		}
		if (i % 2 == 0) {
			temp3 = dp[i / 2] + 1;
		}
		dp[i] = min(temp1, min(temp2, temp3));
	}
	cout << dp[n] << "\n";
}