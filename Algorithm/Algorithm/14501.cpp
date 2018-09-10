#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[20];
int p[20];
int ans = 0;

void go(int sum, int day) {
	if (day == n) {
		ans = max(sum,ans);
		return;
	}
	if (day > n)
		return;

	go(sum, day+1);
	go(sum + p[day], day + t[day]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	go(0, 0);
	cout << ans << "\n";
	return 0;
}