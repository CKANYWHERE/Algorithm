#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int main() {
	int ans = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		
	}
	for (int i = 0; i < 9; i++) {
		ans += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (ans - arr[i] - arr[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (i == k || j == k)
						continue;
					cout << arr[k] << "\n";
				}
			}
		}
	}
}