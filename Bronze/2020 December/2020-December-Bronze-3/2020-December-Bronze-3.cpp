/*
ID: krxnc
TASK: Stuck in a Rut
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

int num;

struct interval {
	int x, y;
	interval() : x(0), y(0) {};
	interval(int x, int y) : x(x), y(y) {};
};

struct vec {
	int x, y, id;
	bool isN;
	vec() : x(0), y(0), id(0), isN(false) {};
	vec(int x, int y, int id, bool isN) : x(x), y(y), id(id), isN(isN) {};
};

// For East
int sortByY(vec A, vec B) {
	if (A.y != B.y)
		return A.y < B.y;
	return A.x < B.x;
}

// For North
int sortByX(vec A, vec B) {
	if (A.x != B.x)
		return A.x < B.x;
	return A.y < B.y;
}

vector<vec> E, N;
vector<vec> v;
vector<interval> eaten;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> num; cin.ignore();
	v.resize(num);
	eaten.resize(num);

	string dir;
	for (int i = 0; i < num; i++) {
		cin >> dir;
		v[i].id = i;
		cin >> v[i].x >> v[i].y;
		if (v[i].isN)
			N.push_back(v[i]);
		else
			E.push_back(v[i]);
	}

	sort(N.begin(), N.end(), sortByX);
	sort(E.begin(), E.end(), sortByY);




	return 0;
}

/*
Case:

12
E 3 5
E 7 5
E 3 9
N 5 3
E 4 6
E 7 6
E 4 10
E 10 4
N 11 2
N 13 2
N 11 6
N 8 1
*/