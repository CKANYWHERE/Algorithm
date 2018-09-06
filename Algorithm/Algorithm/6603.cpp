#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> lotto;

void go(vector<int> &a, int i,int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < lotto.size(); i++) {
			cout << lotto[i];
		}
		cout << "\n";
		return;
	}
	int n = a.size();
	if (n == i) return;
	lotto.push_back(a[i]);
	go(a, i+1, cnt+1);
	lotto.pop_back();
	go(a, i+1, cnt);
}

int main() {

	while (true) {
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		go(a, 0, 0);
		
	}
	return 0;
}