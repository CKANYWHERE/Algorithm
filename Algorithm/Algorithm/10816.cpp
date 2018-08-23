#include "pch.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {
	int n;
	cin >> n;
	int a = 0;
	multiset<int>s;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	int m;
	cin >> m;
	int b=0;
	for (int i = 0; i < m; i++) {
		cin >> b;
		cout << s.count(b) << "\n";
	}
	return 0;
}