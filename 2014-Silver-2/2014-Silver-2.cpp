/*
ID: krxnc
TASK: marathon
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

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(pair<int, int> a) : x(a.first), y(a.second) {}
    Point(int a, int b) : x(a), y(b) {}
    bool equals(Point p) {
        return x == p.x && y == p.y;
    }
    int manDist(Point p) const {
        return abs(p.x - x) + abs(p.y - y);
    }
    int distSq(Point p) const {
        int dx = p.x - x;
        int dy = p.y - y;
        return dx * dx + dy * dy;
    }
};

Point pts[501];
ll dp[501][501];

void solve(ll n, ll k) { // n = current node, k = skips used
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 1e9;
    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            ll cur = dp[i][j];
            for (int skip = 0; skip + j <= k; skip++) {
                int nI = i + skip + 1;
                int nJ = skip + j;
                if (nI > n) break;
                dp[nI][nJ] = min(dp[nI][nJ], dp[i][j] + pts[i].manDist(pts[nI]));
            }
        }
    }
}

int main() {
    ofstream fout("marathon.out");
    ifstream fin("marathon.in");

    ll N, K;
    fin >> N >> K;

    Point p;
    for (int i = 1; i <= N; i++) {
        fin >> p.x >> p.y;
        pts[i] = p;
    }
    solve(N, K);
    fout << dp[N][K] << endl;
}


/*
Unhappy with the poor health of his cows, Farmer John enrolls them in
an assortment of different physical fitness activities.  His prize cow
Bessie is enrolled in a running class, where she is eventually
expected to run a marathon through the downtown area of the city near
Farmer John's farm!

The marathon course consists of N checkpoints (3 <= N <= 500) to be
visited in sequence, where checkpoint 1 is the starting location and
checkpoint N is the finish.  Bessie is supposed to visit all of these
checkpoints one by one, but being the lazy cow she is, she decides
that she will skip up to K checkpoints (K < N) in order to shorten her
total journey.  She cannot skip checkpoints 1 or N, however, since
that would be too noticeable.

Please help Bessie find the minimum distance that she has to run if
she can skip up to K checkpoints.

Since the course is set in a downtown area with a grid of streets, the
distance between two checkpoints at locations (x1, y1) and (x2, y2) is
given by |x1-x2| + |y1-y2|.

INPUT: (file marathon.in)

N (total checkpoints) K (max checkpoints allowed to skip)
N lines... (x, y) of location

The first line gives the values of N and K.

The next N lines each contain two space-separated integers, x and y,
representing a checkpoint (-1000 <= x <= 1000, -1000 <= y <= 1000).
The checkpoints are given in the order that they must be visited.
Note that the course might cross over itself several times, with
several checkpoints occurring at the same physical location.  When
Bessie skips such a checkpoint, she only skips one instance of the
checkpoint -- she does not skip every checkpoint occurring at the same
location.

SAMPLE INPUT:

5 2
0 0
8 3
1 1
10 -5
2 2

OUTPUT: (file marathon.out)

Output the minimum distance that Bessie can run by skipping up to K
checkpoints.  In the sample case shown here, skipping the checkpoints
at (8, 3) and (10, -5) leads to the minimum total distance of 4.

SAMPLE OUTPUT:

4
*/

/*
Solution: We use dynamic programming to solve considering there is only N * K = 250000 cases
which is well within memory range. O(N * K^2) time. 

We take a bottom-up approach in order to create an array where dp[N][K] (Nth node, with K skips used)
is the answer. dp[N][K] = min(dp[N][K], dp[i][j] + dist) where dp[i][j] is any node that can travel to dp[N][K]
*/