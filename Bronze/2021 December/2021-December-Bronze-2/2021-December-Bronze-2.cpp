/*
ID: krxnc
TASK: Air Cownditioning
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

vector<int> p, t, d;

int sgn(int val) {
    return (0 < val) - (val < 0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    p.resize(N);
    t.resize(N);
    d.resize(N + 2);

    for (int i = 0; i < N; i++)
        cin >> p[i];
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        d[i + 1] = p[i] - t[i];
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += abs(d[i] - d[i + 1]);
    }
    cout << ans / 2 << "\n";
}

/*
consider the differences between d[i] terms: -> d[i] - d[i + 1]

    d:  0 1 1 2 2 3 5 5 3 4 4 2 -1 -3 -3 2 0 0 4 1
  dif:  1 0 1 0 1 2 0 2 1 0 2 3  2  0  5 2 0 4 3 1
  
  if the difference is zero, then whatever is done to d[i] must be done to d[i + 1]
  if the difference is not, then one of them needs that difference changed to them ---> here we overcount by two, 
    but with symmetry, we can divide by two and it will be fine.
*/