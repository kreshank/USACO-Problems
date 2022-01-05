/*
ID: krxnc
TASK: milkvisits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N, M, counts[100001], cnt;
char col[100001];
vector<int> adj[100001];

void dfs(int x) {
    if (counts[x]) return;
    counts[x] = cnt;
    for (auto& a : adj[x]) {
        if (col[a] == col[x]) dfs(a); // Find all that have the same color...
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ofstream fout("milkvisits.out");
    ifstream fin("milkvisits.in");

    fin >> N >> M;

    string line;
    fin >> line;
    for (int i = 1; i <= N; i++)
        col[i] = line[i - 1];
    
    int A, B;
    for (int i = 1; i < N; i++) {
        fin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!counts[i]) {
            cnt++;
            dfs(i);
        }
    }

    for (int i = 1; i <= M; i++) {
        int A, B;
        char C;
        fin >> A >> B >> C;
        if (col[A] == C || counts[A] != counts[B]) fout << 1;
        else fout << 0;
    }
    fout << "\n";
    fout.close();
}

/*
Farmer John is planning to build N (1≤N≤10^5) farms that will be connected by N−1 roads,
forming a tree (i.e., all farms are reachable from each-other, and there are no cycles).
Each farm contains a cow, whose breed is either Guernsey or Holstein.

Farmer John's M friends (1≤M≤10^5) often come to visit him. During a visit with friend i,
Farmer John will walk with his friend along the unique path of roads from farm Ai to farm Bi
(it may be the case that Ai=Bi). Additionally, they can try some milk from any cow along the
path they walk. Since most of Farmer John's friends are also farmers, they have very strong
preferences regarding milk. Some of his friends will only drink Guernsey milk, while the remainder
will only drink Holstein milk. Any of Farmer John's friends will only be happy if they can
drink their preferred type of milk during their visit.

Please determine whether each friend will be happy after visiting.

SCORING:
Test cases 2-5 satisfy N≤10^3,M≤2⋅10^3.
INPUT FORMAT (file milkvisits.in):
The first line contains the two integers N and M.
The second line contains a string of length N. The ith character of the string is 'G' if the cow in the ith farm is a Guernsey, or 'H' if the cow in the ith farm is a Holstein.

The next N−1 lines each contain two distinct integers X and Y (1≤X,Y≤N), indicating that there is a road between farms X and Y.

The next M lines contain integers Ai, Bi, and a character Ci.
Ai and Bi represent the endpoints of the path walked during friend i's visit,
while Ci is either G or H if the ith friend prefers Guernsey milk or Holstein milk.

OUTPUT FORMAT (file milkvisits.out):
Print a binary string of length M. The ith character of the string should be '1' if the ith friend will be happy, or '0' otherwise.
SAMPLE INPUT:
5 5
HHGHG
1 2
2 3
2 4
1 5
1 4 H
1 4 G
1 3 G
1 3 H
5 5 H
SAMPLE OUTPUT:
10110
Here, the path from farm 1 and farm 4 involves farms 1, 2, and 4. All of these contain Holsteins, so the first friend will be satisfied while the second one will not.
*/