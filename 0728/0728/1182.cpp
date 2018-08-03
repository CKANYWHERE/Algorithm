#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr[21];
int ans = 0;
int n, s;

void go(int i, int sum) {
	if (i == n && sum == s) {

		ans += 1;
		return;
	}

	if (i == n && sum != s) {
		return;
	}
	go(i + 1, sum + arr[i]);
	go(i + 1, sum);
}


int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	go(0, 0);
	if (s == 0) ans -= 1;
	cout << ans << "\n";
}