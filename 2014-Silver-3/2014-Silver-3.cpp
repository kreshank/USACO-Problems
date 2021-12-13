/*
ID: krxnc
TASK: cowjog
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

ll pos[100001], sp[100001], g[100001];
ll ed[100001];

int main() {
    ofstream fout("cowjog.out");
    ifstream fin("cowjog.in");

    ll N, T;
    fin >> N >> T;
    for (int i = 1; i <= N; i++) {
        fin >> pos[i] >> sp[i];
        ed[i] = pos[i] + sp[i] * T;
    }

    g[N] = 1;
    for (int i = N - 1; i >= 1; i--) {
        if (ed[i] < ed[i + 1]) { // do not intersect
            g[i] = g[i + 1] + 1;
        }
        else {
            g[i] = g[i + 1];
            ed[i] = ed[i + 1];
        }
    }
    fout << g[1] << endl;
}

/*
Problem 3: Cow Jog [Mark Gordon, 2014]

There are N cows jogging on an infinitely-long single-lane track (1 <= N <= 100,000).
Each cow starts at a distinct position on the track, and some cows jog
at different speeds.

With only one lane in the track, cows cannot pass each other.  When a
faster cow catches up to another cow, she has to slow down to avoid
running into the other cow, becoming part of the same running group.

The cows will run for T minutes (1 <= T <= 1,000,000,000).  Please
help Farmer John determine how many groups will be left at this time.
Two cows should be considered part of the same group if they are at
the same position at the end of T minutes.

INPUT: (file cowjog.in)

The first line of input contains the two integers N and T.

The following N lines each contain the initial position and speed of a
single cow.  Position is a nonnegative integer and speed is a positive
integer; both numbers are at most 1 billion.  All cows start at
distinct positions, and these will be given in increasing order in
the input.

SAMPLE INPUT:

5 3
0 1
1 2
2 3
3 2
6 1

OUTPUT: (file cowjog.out)

A single integer indicating how many groups remain after T minutes.

SAMPLE OUTPUT:

3
*/

/*
Obviously, if the ending time (without slowing down) is greater than the one ahead of it,
they must be part of the same group.
*/