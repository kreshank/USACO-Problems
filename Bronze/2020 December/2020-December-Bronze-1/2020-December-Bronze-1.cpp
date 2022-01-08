/*
ID: krxnc
TASK: Do You Know Your ABCs?
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

vector<int> list(7);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for (int i = 0; i < 7; i++) cin >> list[i];

	sort(list.begin(), list.end());

	int A, B, C, AB, BC, CA, ABC;

	A = list[0];
	B = list[1];
	ABC = list[6];

	C = ABC - A - B;

	cout << A << " " << B << " " << C << "\n";
}