#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51]; 
int n,ans=0;
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int temp;
int checklength() {
	int res = 1;
	int maxV = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			if (board[i][j] == board[i][j + 1]) {
				res++;
			}
			else {
				maxV = max(res, maxV);
				res = 1;
			}
		}
		maxV = max(res, maxV);
		for (int j = 0; j < n ; j++) {
			if (board[j][i] == board[j + 1][i]) {
				res++;
			}
			else {
				maxV = max(res, maxV);
				res = 1;
			}
		}
		maxV = max(res, maxV);
	}
	return maxV;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d = 0; d < 2; d++) {
				int nr = i + dx[d];
				int nc = j + dy[d];
				swap(board[i][j],board[nr][nc]);
				ans = max(ans, checklength());
				swap(board[nr][nc], board[i][j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}