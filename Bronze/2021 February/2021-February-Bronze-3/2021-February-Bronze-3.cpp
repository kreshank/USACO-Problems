/*
ID: krxnc
TASK: Clockwise Fence
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//Definitions
typedef pair<int, int> pii;
typedef long long ll;

map<char, int> zid;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	zid['N'] = 0;
	zid['E'] = 1;
	zid['S'] = 2;
	zid['W'] = 3;
	
	int CASES;
	cin >> CASES; cin.ignore();
	while (CASES--) {
		string LINE;
		cin >> LINE;

		int numOfRightTurns = 0;

		char last = LINE[0];
		for (int i = 1; i < LINE.size(); i++) {
			char cur = LINE[i];
			if (cur == last) continue;
			if ((zid[last] + 1) % 4 == zid[cur])
				numOfRightTurns++;
			else
				numOfRightTurns--;
			last = cur;
		}
		if (numOfRightTurns < 0)
			cout << "CCW\n";
		else
			cout << "CW\n";
	}
}