#include "pch.h"
#include<iostream>
using namespace std;
int a[9][9];
bool stop;
bool impossible(int num, int x, int y) {
	int rx = x / 3 * 3, ry = y / 3 * 3;
	for (int i = 0; i < 9; i++)
		if (a[x][i] == num || a[i][y] == num) return false;
	for (int i = rx; i < rx + 3; i++)
		for (int j = ry; j < ry + 3; j++)
			if (a[i][j] == num) return false;
	return true;
}
void go() {
	if (stop) return;
	bool flag = false;
	int x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (a[i][j] == 0) {
				flag = true;
				x = i, y = j;
			}
			if (flag) break;
		}
		if (flag) break;
	}
	if (!flag) {
		stop = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		return;
	}
	for (int i = 1; i < 10; i++) {
		if (impossible(i, x, y)) {
			a[x][y] = i;
			go();
			a[x][y] = 0;
		}
	}

}
int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> a[i][j];
	go();
	return 0;
}
