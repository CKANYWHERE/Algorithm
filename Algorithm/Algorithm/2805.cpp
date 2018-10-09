#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	long long n, m;
	long long maxV = 0;
	cin >> n >> m;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxV = max(maxV, arr[i]);
	}
	long long l = 0;
	long long r = maxV;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long chk = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i]-mid > 0) {
				chk += arr[i] - mid;
			}
		}
		if (chk >= m) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}