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
		maxV = max(maxV,arr[i]);
	}
	long long l = 1;
	long long r = maxV;
	while (l <= r) {
		long long mid = (l + r) / 2;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += arr[i] / mid;
		}
		if (ans >= m) {
			l = mid + 1;
			maxV = min(maxV, mid);
		}
		else
			r = mid - 1;
	}

	cout << maxV << "\n";
	return 0;
}