#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[20][20];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = i;
	}

	int ans = 2147483647;
	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			if (arr[d[i]][d[i + 1]] == 0) {
				ok = false;
			}
			else {
				sum += arr[d[i]][d[i + 1]];
			}
		}
		if (ok && arr[d[n - 1]][d[0]] != 0) {
			sum += arr[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(d.begin() + 1, d.end()));

	printf("%d\n", ans);


	return 0;
}