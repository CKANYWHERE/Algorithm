#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int a[20];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum=0;
		for (int k = 0; k < n; k++) {
			if (i&(1 << k)) {
				sum += a[k];
			}
		}
		if (sum == m) {
			ans += 1;
		}
	}

	cout << ans << "\n";

	return 0;
}