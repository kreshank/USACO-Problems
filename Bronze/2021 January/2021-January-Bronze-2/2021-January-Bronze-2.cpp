/*
ID: krxnc
TASK: Even More Odd Photos
LANG: C++
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

//Definitions
typedef pair<int, int> pii;
typedef long long ll;

int N, evens = 0, odds = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	int id;
	for (int i = 0; i < N; i++) {
		cin >> id;
		if (id % 2) odds++;
		else evens++;
	}

	if (evens > odds) {
		cout << 2 * odds + 1 << "\n";
		return 0;
	}
	else if (evens == odds) {
		cout << 2 * odds << "\n";
		return 0;
	}
	else {
		int dif = odds - evens;
		if (dif % 3 == 0 || dif % 3 == 2) {
			cout << evens * 2 + 2 * dif / 3 << "\n";
			return 0;
		}
		cout << evens * 2 + 2 * dif / 3 - 1 << "\n";
	}
}