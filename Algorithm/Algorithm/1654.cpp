#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
long long arr[10000];
int n, m;
int main() {
	cin >> n >> m;
	long long maxV = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxV = max(maxV, arr[i]);
	}

	long long left = 0;
	long long right = maxV;
	long long res = 0;

	while (left <= right) {
		long long mid = (left + right)/2;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += arr[i] / mid;
		}
		if (ans == m) {
			left = mid + 1;
			res = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << res << "\n";

	return 0;
}