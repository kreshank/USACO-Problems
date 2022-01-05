/*
ID: krxnc
TASK: Acowdemia I
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L;
vector<int> C;

bool valid(int m) {
    int hold = L;
    for (int i = N - m; i < N; i++) {
        if (C[i] < m) {
            hold--;
            if (C[i] + 1 < m) return false;
        }
    }
    return hold >= 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> L;
    C.resize(N);
    
    for (int i = 0; i < N; i++) 
        cin >> C[i];
    
    sort(C.begin(), C.end());

    int min = 0, max = N;
    while (min < max) {
        int mid = (min + max + 1) / 2;
        if (valid(mid))
            min = mid;
        else
            max = mid - 1;
    }

    cout << min << "\n";
}