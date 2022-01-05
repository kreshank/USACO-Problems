/*
ID: krxnc
TASK: Acowdemia II
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int K, N;
map<string, int> id;
int seniority[101][101]; // 0 = not done, 1 = definitely more, 2 = definitely less, 3 = unknown

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        id[str] = i;
    }

    vector<string> rep(N);
    for (int report = 0; report < K; report++) {
        for (int i = 0; i < N; i++) cin >> rep[i];

        for (int i = 0; i < N; i++) {
            bool alpha = true;
            for (int j = i + 1; j < N; j++) {
                int iID = id[rep[i]], jID = id[rep[j]];
                
                int &cur = seniority[iID][jID], &oth = seniority[jID][iID];

                if (rep[j - 1] >= rep[j] || !alpha) { // If not in alphabetical order, can draw conclusions
                    alpha = false;
                    if (cur == 0) {
                        cur = 1;
                        oth = 2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) cout << "B";
            else if (seniority[i][j] == 0) cout << "?";
            else cout << seniority[i][j] - 1;
        }
        cout << "\n";
    }
}

/*
Possible cases:

A , B , C

A definitely less than B
A definitely more than B
A either more than, or equal to B    (same thing as unknown, prerequisite is that it must be in alphabetical order)
*/