#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 50;
int N, K, result;
string word[MAX];
bool visited[26];

void howMany(int alpha, int cnt)
{
	//K개를 다 배운 경우
	if (cnt == K)
	{
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			bool flag = true;
			//익히지 않은 알파벳이 있는 경우 배울 수 없는 단어
			for (int j = 0; j < word[i].length(); j++)
				if (!visited[word[i][j] - 'a'])
				{
					flag = false;
					break;
				}
			if (flag)
				temp++;
		}
		result = max(result, temp);
		return;
	}
	//아직 K개를 배우지 않은 경우: 브루트포스
	for (int c = alpha; c < 26; c++)
	{
		if (!visited[c])
		{
			visited[c] = true;
			howMany(c, cnt + 1);
			visited[c] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	//ANTA, TICA 무조건 포함

	if (K < 5)
	{
		cout << 0 << "\n";
		return 0;
	}
	//전부 익힐 수 있다
	else if (K == 26)
	{
		cout << N << "\n";
		return 0;
	}
	K -= 5;
	for (int i = 0; i < N; i++)
	{
		cin >> word[i];
		//anta
		word[i] = word[i].substr(4, word[i].length());
	//tica
		for (int j = 0; j < 4; j++)
			word[i].pop_back();
	}

	visited['a' - 'a'] = true;
	visited['c' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;

	howMany(0, 0);
	cout << result << "\n";
	return 0;

}