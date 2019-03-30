#include "pch.h"
#include <iostream>
using namespace std;

int n, m, broke[10] = { 0, };

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		broke[a] = 1;
	}
	int Min = (n - 100) < 0 ? -1 * (n - 100) : n - 100;
	for (int i = 0; i <= 1000000; i++) {
		int channel = i;
		int leng = 0;
		bool flag = false;
		// 채널의 자릿수를 구해서 누를수있는지 판별 누를수있으면 Min값이랑 비교
		while (1) {
			if (broke[channel % 10])
				break;
			else {
				channel /= 10;
				leng++;
				if (channel == 0) {
					flag = true;
					break;
				}
			}
		}
		if (flag) {
			int result = (n - i) < 0 ? -1 * (n - i) : n - i;
			if (result + leng < Min)
				Min = result + leng;
		}
	}
	cout << Min << '\n';
	return 0;
}
