#include "stdafx.h"
#include <iostream>
using namespace std;
int T[10];
int P[1010];
int n;
int ans = 0;

void solve(int day, int sum) {
	if (day == n) {
		if (sum > ans)
			ans = sum;
	}
	if (day > n)
		return;

	solve(day + T[day], sum + P[sum]);
	solve(day + 1,sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> T[i];
		cin >> P[i];
	}
	cout << ans << "\n";
	solve(0,0);
}