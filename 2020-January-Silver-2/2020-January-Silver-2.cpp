/*
ID: krxnc
TASK: loan
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

ll N, K, M;

bool check(ll mid) {
    ll G = 0, Y = 0, days = K;
    while (G < N && days > 0) {
        Y = (N - G) / mid;
        if (M > Y) {
            return (N - G + M - 1) / M <= days;
        }
        ll max = N - mid * Y;
        ll num = (max - G) / Y + 1;
        num = min(num, days);
        G += Y * num;
        days -= num;
    }
    return G >= N;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ofstream fout("loan.out");
    ifstream fin("loan.in");

    fin >> N >> K >> M;

    ll min = 1, max = N;
    while (min < max) {
        ll mid = (min + max + 1) / 2;
        if (check(mid)) {
            min = mid;
        }
        else {
            max = mid - 1;
        }
    }

    fout << min << endl;

    return 0;
}

/*
SAMPLE INPUT:
10 3 3
SAMPLE OUTPUT:
2
*/