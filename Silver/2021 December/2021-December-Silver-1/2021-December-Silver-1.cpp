/*
Submitted on contest date, 17/21, fail.
*/

/*
ID: krxnc
TASK: Closest Cow Wins
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <set>

using namespace std;
typedef pair<int, int> pii;

const int lim = 200010;

int K, M, N;
int pi, ti;
int fi;

vector<pii> patches, events; // position, tastiness
vector<int> nhoj; 
vector<long long> candidates;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> M >> N;
    for (int i = 0; i < K; i++) {
        cin >> pi >> ti;
        patches.push_back({ pi, ti });
    }

    sort(patches.begin(), patches.end());

    nhoj.push_back(-100000000);
    for (int i = 1; i <= M; i++) {
        cin >> fi;
        nhoj.push_back(fi);
    }
    nhoj.push_back(100000000);

    sort(nhoj.begin(), nhoj.end());

    int nPtr = 1;
    for (int i = 0; i < K; i++) {
        int x = patches[i].first;
        while (nPtr <= M + 1 && nhoj[nPtr] <= x) { // Stops when they swap from below to above
            nPtr++;
        }
        int dist = min(abs(x - nhoj[nPtr]), abs(x - nhoj[nPtr - 1]));
        if (dist == 0) continue;
        events.push_back({ max(0, x - dist + 1), patches[i].second });
        events.push_back({ x + dist, -patches[i].second });
    }

    sort(events.begin(), events.end());

    for (int i = 0; i < events.size(); i++) {
        long long runningSum = events[i].second;
        long long hold = 0;
        while (runningSum) {
            hold = max(hold, runningSum);
            runningSum += events[++i].second;
            hold = max(hold, runningSum);
        }
        candidates.push_back(hold);
    }

    sort(candidates.begin(), candidates.end());
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += (long long)candidates[candidates.size() - i];
    }
    cout << sum << "\n";
}


// 17/21