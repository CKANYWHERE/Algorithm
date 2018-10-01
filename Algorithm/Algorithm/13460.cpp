#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;
char map[20][20];
struct nodes {
	int redR;
	int redC;
	int blueR;
	int blueC;
	int redGoal = 0;
	int blueGoal = 0;
	int cnt = 0;
};

int main() {
	int n, m;
	cin >> n >> m;
	nodes node;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				node.redR = i, node.redC = j;
			}
			if (map[i][j] == 'B') {
				node.blueR = i, node.blueC = j;
			}
		}
	}
	queue<nodes> q;
	q.push(node);

	while (!q.empty()) {

		if (q.front().cnt == 10) {
			cout << -1 << "\n";
			break;
		}
		//µ¿ ¼­ ³² ºÏ 4¹æÇâµ¼
		for (int i = 0; i < 4; i++) {
			//µ¿
			if (i == 0) {
				nodes tmp = q.front();
				int redNr = q.front().redR;
				int blueNr = q.front().blueR;
				int redNc = q.front().redC;
				int blueNc = q.front().blueC;
				while (map[redNr][redNc + 1] != '#') {
					if (map[redNr][redNc] == 'O') {
						tmp.redGoal = 1;
					}
					redNc++;
				}
				while (map[blueNr][blueNc + 1] != '#') {
					if (map[blueNr][blueNc] == 'O') {
						tmp.blueGoal = 1;
					}
					blueNc++;
				}
				if (blueNr == redNr && blueNc == redNc) {
					if (tmp.redC < tmp.blueC) {
						redNc--;
					}
					else {
						blueNc--;
					}
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 1) {
					cout << tmp.cnt <<"\n";
					return 0;
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 0) {
					tmp.cnt++;
					tmp.blueC = blueNc;
					tmp.redC = redNc;
					q.push(tmp);
				}
			
			}
			//¼­
			else if (i == 1) {
				nodes tmp = q.front();
				int redNr = q.front().redR;
				int blueNr = q.front().blueR;
				int redNc = q.front().redC;
				int blueNc = q.front().blueC;
				while (map[redNr][redNc - 1] != '#') {
					if (map[redNr][redNc] == 'O') {
						tmp.redGoal = 1;
					}
					redNc--;
				}
				while (map[blueNr][blueNc - 1] != '#') {
					if (map[blueNr][blueNc] == 'O') {
						tmp.blueGoal = 1;
					}
					blueNc--;
				}
				if (blueNr == redNr && blueNc == redNc) {
					if (tmp.redC < tmp.blueC) {
						blueNc++;
					}
					else {
						redNc++;
					}
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 1) {
					cout << tmp.cnt << "\n";
					return 0;
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 0) {
					tmp.cnt++;
					tmp.blueC = blueNc;
					tmp.redC = redNc;
					q.push(tmp);
				}
			}
			//³²
			else if (i == 2) {
				nodes tmp = q.front();
				int redNr = q.front().redR;
				int blueNr = q.front().blueR;
				int redNc = q.front().redC;
				int blueNc = q.front().blueC;
				while (map[redNr+1][redNc] != '#') {
					if (map[redNr][redNc] == 'O') {
						tmp.redGoal = 1;
					}
					redNr++;
				}
				while (map[blueNr+1][blueNc] != '#') {
					if (map[blueNr][blueNc] == 'O') {
						tmp.blueGoal = 1;
					}
					blueNr++;
				}
				if (blueNr == redNr && blueNc == redNc) {
					if (tmp.redR < tmp.blueR) {
						redNr--;
					}
					else {
						blueNr--;
					}
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 1) {
					cout << tmp.cnt << "\n";
					return 0;
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 0) {
					tmp.cnt++;
					tmp.blueR = blueNr;
					tmp.redR = redNr;
					q.push(tmp);
				}
			}

			//ºÏ
			else  {
				nodes tmp = q.front();
				int redNr = q.front().redR;
				int blueNr = q.front().blueR;
				int redNc = q.front().redC;
				int blueNc = q.front().blueC;
				while (map[redNr - 1][redNc] != '#') {
					if (map[redNr][redNc] == 'O') {
						tmp.redGoal = 1;
					}
					redNr--;
				}
				while (map[blueNr + 1][blueNc] != '#') {
					if (map[blueNr][blueNc] == 'O') {
						tmp.blueGoal = 1;
					}
					blueNr--;
				}
				if (blueNr == redNr && blueNc == redNc) {
					if (tmp.redR < tmp.blueR) {
						blueNr++;
					}
					else {
						redNr++;
					}
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 1) {
					cout << tmp.cnt<< "\n";
					return 0;
				}
				if (tmp.blueGoal == 0 && tmp.redGoal == 0) {
					tmp.cnt++;
					tmp.blueR = blueNr;
					tmp.redR = redNr;
					q.push(tmp);
				}
			}
		}
		q.pop();
	}
	return 0;
}