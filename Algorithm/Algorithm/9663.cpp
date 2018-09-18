#include "pch.h"
#include <iostream>

using namespace std;

int n;
int ans = 0;
bool board[20];
bool check[40];
bool check2[40];

void go(int r,int cnt) {
	
	if (cnt == n) {
		ans += 1; 
		return;
	}

	for (int i = 0; i < n; i++) {
		if (board[i] || check[r + i] || check2[n - i + r - 1])
			continue;

		board[i] = true;
		check[r + i] = true;
		check2[n - i + r - 1] = true;
		
		go(r + 1, cnt + 1);


		board[i] = false;
		check[r + i] = false;
		check2[n - i + r - 1] = false;
	}

}

int main() {
	
	cin >> n;
	go(0,0);

	cout << ans << "\n";

	return 0;
}