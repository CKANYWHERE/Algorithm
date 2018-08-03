#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(string &password) {
	int ja = 0;
	int mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			mo += 1;
		}
		else {
			ja += 1;
		}
	}
	return ja >= 2 && mo >= 1;
}

void go(int i, string pw, int n, vector<char> &alpha) {

	if (pw.length() == n) {
		if(check(pw)){
			cout << pw << "\n";
			return;
		}
	}
	if (alpha.size() <= i) return;
	go(++i, pw + alpha[i], n, alpha);
	go(++i, pw, n, alpha);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	go(0,"",n,a);
}