#include "pch.h"
#include <iostream>
#include <queue>
using namespace std;

bool visitied[1000001];

int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	int ans = -1, cnt = 0, stair = 0;
	queue<pair<int, int>> q;
	visitied[s] = true;
	q.push(make_pair(s,0));
	while (!q.empty()) {
		stair = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (stair == g) {
			ans = cnt;
		}

		if (stair + u <= f && visitied[stair + u ] == false) {
			q.push(make_pair(stair +u,cnt + 1));
			visitied[stair + u] = true;
		}

		if (stair - d > 0 && visitied[stair - d] == false) {
			q.push(make_pair(stair - d, cnt + 1));
			visitied[stair - d] = true;
		}
	}
	if (ans == -1)cout << "use the stairs\n";
	else cout << ans << "\n";

	return 0;
}