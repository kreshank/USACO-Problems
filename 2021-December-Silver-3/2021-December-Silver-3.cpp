/*
ID: krxnc
TASK: Convoluted Intervals
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
#include <map>

using namespace std;

const int lim = 200010;

int Aprefix[10100], Bprefix[10100]; // let Aprefix[0] represent -1. 
map<int, int> a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, M;
    cin >> N >> M;

    int ai, bi;
    for (int i = 0; i < N; i++) {
        cin >> ai >> bi;
        a[ai]++;
        b[bi]++;
    }

    for (auto k1 : a) {
        for (auto k2 : a) {
            if (k1.first < k2.first) {
                Aprefix[2 * M + 1] += k1.second * k2.second * 2;
                Aprefix[min(k1.first + k1.first + 1, 2 * M + 1)] -= k1.second * k2.second * 2;
            }
            else if (k1 == k2) {
                Aprefix[2 * M + 1] += k1.second;
                Aprefix[min(k1.first * 2, 2 * M + 1)] -= k1.second;
            }
        }
    }
    for (auto k1 : b) {
        for (auto k2 : b) {
            if (k1.first < k2.first) {
                Bprefix[1] += k1.second * k2.second * 2;
                Bprefix[min(k1.first + k2.first + 2, 2 * M + 1)] -= k1.second * k2.second * 2;
            }
            else if (k1 == k2) {
                Bprefix[1] += k1.second;
                Bprefix[min(k1.first * 2 + 2, 2 * M + 2)] -= k1.second;
            }
        }
    }

    for (int i = 1; i <= 1 + 2 * M; i++) {
        Bprefix[i] += Bprefix[i - 1];
    }

    for (int i = 2 * M + 1; i >= 1; i--) {
        Aprefix[i] += Aprefix[i + 1];
    }

    for (int i = 1; i <= 2 * M + 1; i++) {
        cout << min(Aprefix[i], Bprefix[i]) << "\n";
    }
}