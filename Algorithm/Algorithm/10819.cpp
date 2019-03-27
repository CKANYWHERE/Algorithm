#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculate(vector<int> v) {
	int sum = 0;
	for (int i = 1; i < v.size(); i < i++) {
		sum += abs(v[i]-v[i-1]);
	}

	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int res = 0;

	do {
		int temp = calculate(v);
		res = max(res, temp);
	} while (next_permutation(v.begin(), v.end()));
	cout << res << "\n";
	return 0;
}
