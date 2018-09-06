#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

bool check(string &password) {
	int ja = 0;
	int mo = 0;
	bool check = false;

	for (int i = 0; i < password.length(); i++) {
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i'
			|| password[i] == 'o' || password[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	if (mo >= 2 && ja >= 1) check = true;
	return check;
}

void go(vector<char> &alpha, string password, int i) {
	if (password.length() == n) {
		if (check(password)) {
			cout << password << "\n";
		}
		return;
	}
	if (i == alpha.size()) return;
	go(alpha, password, i + 1);
	go(alpha, password + alpha[i], i + 1);
}


int main() {
	
	cin >> n >> m;
	vector<char> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	go(a , "", 0);
	return 0;
}