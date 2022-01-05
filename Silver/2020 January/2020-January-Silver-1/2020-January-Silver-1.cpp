/*
ID: krxnc
TASK: berries
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
#include <queue>

using namespace std;

const int maxN = 1005;

int trees[maxN];
int N, K, b = 1; // N = trees, K = baskets

int comp(int A, int B) { 
    return (A % b) > (B % b); 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ofstream fout("berries.out");
    ifstream fin("berries.in");

    fin >> N >> K;

    int upB= -1;
    for (int i = 0; i < N; i++) {
        fin >> trees[i];
        upB = max(upB, trees[i]);
    }

    int best = 0;
    for (b = 1; b <= upB; b++) {
        int elsie = 0;
        for (int i = 0; i < N; i++) {
            elsie += trees[i] / b;
        }
        if (elsie < K / 2)
            break;
        if (elsie >= K) {
            best = max(best, b * K / 2);
            continue;
        }
        sort(trees, trees + N, comp);
        int hold = b * (elsie - K / 2);
        for (int i = 0; i < N; i++) {
            if (i + elsie >= K) break;
            hold += trees[i] % b;
        }
        best = max(hold, best);
    }
    fout << best << "\n";
}

/*
SAMPLE INPUT:
5 4
3 6 8 4 2
SAMPLE OUTPUT:
8
*/