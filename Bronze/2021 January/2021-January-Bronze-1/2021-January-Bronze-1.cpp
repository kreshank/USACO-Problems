/*
ID: krxnc
TASK: Uddered but not Herd
LANG: C++
*/

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Definitions
typedef pair<int, int> pii;
typedef long long ll;

string alphabet, sound;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> alphabet >> sound;

	int count = 0, index = 0;
	while (index < sound.size()) {
		count++;
		for (auto c : alphabet) {
			if (c == sound[index])
				index++;
		}
	}

	cout << count << "\n";
}