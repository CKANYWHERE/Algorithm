#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int n;
bool finish;
bool check(string s) {
	int len = s.length();
	int start = len - 1;
	
	for (int i = 1; i <= len / 2; i++) {
		string first = s.substr(start-i,i);
		string second = s.substr(start, i);
		if (!first.compare(second)) return false;
		--start;
	}
	return true;
}

void go(int i, string s) {
	if (finish) return;
	if (!check(s)) return;
	if (i == n) {
		cout << s << "\n";
		finish = true;
		return;
	}

	go(i + 1, s + "1");
	go(i + 1, s + "2");
	go(i + 1, s + "3");
}

int main() {
	
	cin >> n;
	go(1, "1");
	return 0;
}
