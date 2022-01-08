/*
ID: krxnc
TASK: Daisy Chains
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

int N;
vector<int> petals;
vector<int> pSum;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	petals.resize(N + 1);
	pSum.resize(N + 1);

	for (int i = 1; i <= N; i++) cin >> petals[i];

	for (int i = 1; i <= N; i++) pSum[i] = petals[i] + pSum[i - 1];

	int ans = 0;
	for (int start = 1; start <= N; start++) {
		for (int end = start; end <= N; end++) {
			int sum = pSum[end] - pSum[start - 1];
			int dif = end - start + 1;
			if (sum % dif == 0)
				for (int i = start; i <= end; i++) {
					if (petals[i] == sum / dif) {
						ans++;
						break;
					}
				}
		}
	}
	cout << ans << "\n";

	return 0;
}