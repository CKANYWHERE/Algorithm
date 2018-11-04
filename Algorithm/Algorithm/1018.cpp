#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int MIN = 987654321;
int board[51][51];
int caseA[8][8];
int caseB[8][8];

int check(int r, int c) {
	int a=0, b=0;
	for (int i = r; i < r + 8; i++) {
		for (int j = c; j < c + 8; j++) {
			if (caseA[i - r][j - c] != board[i][j])
				a++;
			if (caseB[i - r][j - c] != board[i][j])
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
			if ((i+j)%2==0) {
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
			char tmp;
			cin >> tmp;
			if (tmp == 'W')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}
	int minV = 987654321;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int ans = check(i, j);
			minV = min(minV, ans);
		}
	}
	cout << minV << "\n";
	return 0;
}