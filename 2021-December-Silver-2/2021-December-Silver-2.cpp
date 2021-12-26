/*
ID: krxnc
TASK: Connecting Two Barns
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <stack>
#include <set>

using namespace std;

vector<vector<int>> adj;
int colors[100005];
int N = 0, M;

int sq(int x) {
    return x * x;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int TESTCASES;
    cin >> TESTCASES;

    while (TESTCASES--) {
        memset(colors, 0, sizeof(colors));
        adj.clear();
        cin >> N >> M; // N fields, M paths made
        adj.resize(N + 1);
        int a, b;
        
        // O(M)
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // O(N + M)
        int colorCount = 0;
        for (int i = 1; i <= N; i++) {
            if (colors[i]) continue;
            colorCount++;
            colors[i] = colorCount;
            stack<int> s;
            s.push(i);
            while (s.size()) {
                int t = s.top();
                s.pop();
                for (int w : adj[t]) {
                    if (!colors[w]) {
                        s.push(w);
                        colors[w] = colors[t];
                    }
                }
            }
        }

        if (colors[1] == colors[N]) {
            cout << 0 << "\n";
            continue;
        }



        for (int i = 1; i <= N; i++) cout << colors[i] << " ";
    }
    return 0;
}

/*
4
5 2
1 2
4 5
5 3
1 2
2 3
4 5
5 3
1 2
2 3
3 5
20 4
1 4
4 8
8 14
12 20

1
20 4
1 4
4 8
8 16
12 20
*/