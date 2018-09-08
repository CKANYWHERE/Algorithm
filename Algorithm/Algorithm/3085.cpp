#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51]; 
int n,ans=0;
int dx[] = { 0,1 };
int dy[] = { 1,0 };


int checklength() {
	int res = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1]) cnt++;
			else res = max(res, cnt), cnt = 0;
		}
		res = max(res, cnt), cnt = 0;
		for (int j = 0; j < n - 1; j++) {
			if (board[j][i] == board[j + 1][i]) cnt++;
			else res = max(res, cnt), cnt = 0;
		}
		res = max(res, cnt), cnt = 0;
	}
	return res;
}

int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d = 0; d < 2; d++) {
				int nx = i + dx[d];
				int ny = i + dy[d];
				swap(board[i][j],board[nx][ny]);
				ans = max(ans, checklength());
				swap(board[nx][ny], board[i][j]);
			}
		}
	}

	cout << ans << "\n";
	return 0;
}