#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int MIN = 987654321;
int board[51][51];
int caseA[8][8];
int caseB[8][8];

int cal(int x, int y) {
	int a = 0, b = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (caseA[i - x][j - y] != board[i][j])
				a++;
			if (caseB[i - x][j - y] != board[i][j])
				b++;
		}
	}
	return a > b ? b : a;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2) {
				caseA[i][j] = 1;
				caseB[i][j] = 0;
			}
			else {
				caseA[i][j] = 0;
				caseB[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			if (a == 'W')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int ans = cal(i, j);
			MIN = min(MIN, ans);
		}

	}

	cout << MIN << "\n";
	return 0;
}