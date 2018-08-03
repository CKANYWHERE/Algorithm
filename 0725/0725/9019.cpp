#include "stdafx.h"
#include <queue>
#include <iostream>
#include <string>

const int MAX = 100010;
using namespace std;

int dist[10000];
int from[10000];
bool check[10000];
char ans[10000];


int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		queue<int> q;
		int n, k;
		cin >> n >> k;

		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(ans, 0, sizeof(ans));
		memset(from, 0, sizeof(from));

		q.push(n);
		check[n] = true;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			int index = (now * 2) % 10000;
			if (check[(now * 2) % 10000] == false) {
				q.push(index);
				ans[index] = 'D';
				dist[index] = dist[now] + 1;
				from[index] = now;
				check[index] = true;
			}

			index = now - 1;
			if (now == 0) index = 9999;
			if (check[index] == false) {
				q.push(index);
				ans[index] = 'S'; from[index] = now;
				dist[index] = dist[now] + 1;
				check[index] = true;
			}

			index = (now % 1000) * 10 + now / 1000;
			if (check[index] == false) {
				q.push(index);
				ans[index] = 'L'; from[index] = now;
				dist[index] = dist[now] + 1;
				check[index] = true;
			}
			
			index = (now / 10) + (now % 10) * 1000;
			if (check[index] == false) {
				q.push(index);
				ans[index] = 'R'; from[index] = now;
				dist[index] = dist[now] + 1;
				check[index] = true;
			}
		}
		string res;
		while (k != n) {
			res += ans[k];
			k = from[k];
		}
		reverse(res.begin(), res.end());

		cout << res << "\n";
	}


}