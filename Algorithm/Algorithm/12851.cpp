#include "pch.h"
#include<iostream>
#include<queue>
using namespace std;

#define MAX_SIZE 100001
#define INF 987654321

int map[MAX_SIZE];
int visit[MAX_SIZE];
queue<int> q;
int n, k, sec, MIN, cnt;

void BFS() {

	int size;

	while (!q.empty()) {

		size = q.size();
		sec++;

		for (int i = 0; i < size; i++) {

			int now = q.front();
			visit[now] = 1;
			q.pop();

			if (now == k) {

				if (sec <= MIN) {
					MIN = sec;
					cnt++;
				}

				else return;
			}

			// X - 1
			int next = now - 1;

			if (0 <= next && visit[next] == 0) {
				q.push(next);
			}

			// X + 1
			next = now + 1;
			if (next <= 100000 && visit[next] == 0) {
				q.push(next);
			}

			// 2*X
			next = now * 2;
			if (next <= 100000 && visit[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	MIN = INF;
	sec = -1;
	cnt = 0;
	visit[n] = 1;
	q.push(n);
	BFS();

	cout << MIN << '\n';
	cout << cnt << '\n';

	return 0;
}