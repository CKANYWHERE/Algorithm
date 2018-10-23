#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
	int r;
	int c;
	int dir;
	int type;
};

int board[9][9];
int dist[9][9];
int n, m;
int ans = 987654321;
vector<info> cctv;

//밑 체크
void check0(int r, int c) {

	for (int i = c; i < m; i++) {
		if (dist[r][i] == 6)break;
		if (dist[r][i] == 0) dist[r][i] = -1;
	}
}

//오른쪽 체크
void check1(int r, int c) {
	for (int i = r; i < n; i++) {
		if (dist[i][c] == 6) break;
		if (dist[i][c] == 0) dist[i][c] = -1;
	}
}

//위 체크
void check2(int r, int c) {
	for (int i = c; i >= 0; i--) {
		if (dist[r][i] == 6)break;
		if (dist[r][i] == 0) dist[r][i] = -1;
	}
}

//왼쪽 체크
void check3(int r, int c) {
	for (int i = r; i >= 0; i--) {
		if (dist[i][c] == 6) break;
		if (dist[i][c] == 0) dist[i][c] = -1;
	}
}

void checkCctv(vector<info> &cctv) {
	for (int i=0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = board[i][j];
		}
	}
	for (int k = 0; k < cctv.size(); k++) {
		if (cctv[k].type == 1) {
			if (cctv[k].dir == 0) check0(cctv[k].r, cctv[k].c);
			if (cctv[k].dir == 1) check1(cctv[k].r, cctv[k].c);
			if (cctv[k].dir == 2) check2(cctv[k].r, cctv[k].c);
			if (cctv[k].dir == 3) check3(cctv[k].r, cctv[k].c);
		}

		if (cctv[k].type == 2) {
			if (cctv[k].dir == 0 || cctv[k].dir == 2) {
				check0(cctv[k].r, cctv[k].c);
				check2(cctv[k].r, cctv[k].c);
			}
			if (cctv[k].dir == 1 || cctv[k].dir == 3) {
				check1(cctv[k].r, cctv[k].c);
				check3(cctv[k].r, cctv[k].c);
			}
		}

		if (cctv[k].type == 3) {
			if (cctv[k].dir == 0) {
				check2(cctv[k].r, cctv[k].c);
				check3(cctv[k].r, cctv[k].c);
			}
			if (cctv[k].dir == 1) {
				check0(cctv[k].r, cctv[k].c);
				check3(cctv[k].r, cctv[k].c);
			}
			if (cctv[k].dir == 2) {
				check0(cctv[k].r, cctv[k].c);
				check1(cctv[k].r, cctv[k].c);
			}

			if (cctv[k].dir == 3) {
				check1(cctv[k].r, cctv[k].c);
				check2(cctv[k].r, cctv[k].c);
			}	

		}

		if (cctv[k].type == 4) {
			if (cctv[k].dir == 0) {
				check0(cctv[k].r, cctv[k].c);
				check1(cctv[k].r, cctv[k].c);
				check2(cctv[k].r, cctv[k].c);
			}
			if (cctv[k].dir == 1) {
				check1(cctv[k].r, cctv[k].c);
				check2(cctv[k].r, cctv[k].c);
				check3(cctv[k].r, cctv[k].c);
			}

			if (cctv[k].dir == 2) {
				check0(cctv[k].r, cctv[k].c);
				check2(cctv[k].r, cctv[k].c);
				check3(cctv[k].r, cctv[k].c);
			}

			if (cctv[k].dir == 3) {
				check0(cctv[k].r, cctv[k].c);
				check1(cctv[k].r, cctv[k].c);
				check3(cctv[k].r, cctv[k].c);
			}
		}

		if (cctv[k].type == 5) {
			check0(cctv[k].r, cctv[k].c);
			check1(cctv[k].r, cctv[k].c);
			check2(cctv[k].r, cctv[k].c);
			check3(cctv[k].r, cctv[k].c);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0)cnt++;
		}
	}

	ans = min(ans, cnt);
}

void go(int i, vector<info> &cctv) {

	if (i == cctv.size()) {
		checkCctv(cctv);
		return;
	}
	
	cctv[i].dir = 0;
	go(i + 1, cctv);

	cctv[i].dir = 1;
	go(i + 1, cctv);

	cctv[i].dir = 2;
	go(i + 1, cctv);

	cctv[i].dir = 3;
	go(i + 1, cctv);

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] < 6) {
				cctv.push_back({ i, j, 0, board[i][j] });
			}
		}
	}

	go(0, cctv);
	cout << ans << "\n";

	return 0;
}