#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &n, vector<char> &c) {

	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '<' && n[i] > n[i + 1])
			return false;
		if (c[i] == '>' && n[i] < n[i + 1])
			return false;
	}

	return true;
}


int main() {
	int n;
	cin >> n;
	vector<int> small(n + 1);
	vector<int> big(n + 1);
	vector<char> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i <= n; i++) {
		big[i] = 9 - i;
		small[i] = i;
	}

	do {
		if (check(small, a)) break;
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (check(big, a)) break;
	} while (prev_permutation(big.begin(), big.end()));


	for (int i = 0; i < big.size(); i++) {
		cout << big[i];
	}
	cout << "\n";

	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << "\n";
	return 0;
}