/*
ID: krxnc
TASK: Lonely Photo
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
#include <cstring>
using namespace std;

typedef long long ll;

int N;
vector<int> G, H;

void cnt(ll &sum, vector<int> &A) {
    ll s = 0, f = 1, e;
    while (f <= N && A[f] == A[s]) f++;
    e = f;
    while (f <= N) {
        while (e <= N && A[e] == A[f]) e++;

        if (e - s > 3) {
            sum += (f - s) * (e - f) - 1;
            if (e - f > 1) sum--;
            if (f - s > 1) sum--;
        }
        s = f;
        f = e;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    G.resize(N + 5);
    H.resize(N + 5);

    cin.ignore();

    string L;
    cin >> L;
    for (int i = 1; i <= N; i++) {
        if (L[i - 1] == 'G') G[i]++;
        else H[i]++;
        G[i] += G[i - 1];
        H[i] += H[i - 1];
    }

    ll sum = 0;

    cnt(sum, G);
    cnt(sum, H);

    cout << sum << "\n";
}

/*
18
GHHHHHHGHGHGGGHHGH

50
GGGGGGGGGGGGGGGGGGGGGGGGGHGGGGGGGGGGGGGGGGGGGGGGGG
*/