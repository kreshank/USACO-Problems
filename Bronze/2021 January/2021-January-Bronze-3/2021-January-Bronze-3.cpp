/*
ID: krxnc
TASK: Just Stalling
LANG: C++
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

//Definitions
typedef pair<int, int> pii;
typedef long long ll;

int N;
vector<int> heights, stalls;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;
	heights.resize(N + 1);
	stalls.resize(N);

	for (int i = 0; i < N; i++) cin >> heights[i];
	heights[N] = INT_MAX;

	for (int i = 0; i < N; i++) cin >> stalls[i];

	sort(heights.begin(), heights.end());
	sort(stalls.begin(), stalls.end());
	
	ll ans = 1;
	int a = 0, b = 0;
	while (b < N) {
		while (a < N && heights[a] <= stalls[b]) a++;
		ans *= (ll) max(a - b, 0);
		b++;
	}
	cout << ans << "\n";
}