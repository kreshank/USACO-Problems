/*
ID: krxnc
TASK: Walking Home
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

char grid[55][55];
int N, K;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TESTCASES;
    cin >> TESTCASES;

    while (TESTCASES--) {
        cin >> N >> K;
        cin.ignore();

        for (int i = 1; i <= N; i++) {
            cin >> grid[i] + 1;
        }

        int sum = 0, i;
        if (K >= 1) {
            bool horiz = true, vert = true;
            for (i = 1; i <= N; i++) {
                if (grid[1][i] == 'H') horiz = false;
                if (grid[i][1] == 'H') vert = false;
            }
            for (i = 1; i <= N; i++) {
                if (grid[i][N] == 'H') horiz = false;
                if (grid[N][i] == 'H') vert = false;
            }
            sum = horiz + vert;
        }
        if (K >= 2) {
            for (int row = 2; row <= N - 1; row++) {
                bool horiz = true, vert = true;
                for (i = 1; i <= row; i++) {
                    if (grid[1][i] == 'H') horiz = false;
                    if (grid[i][1] == 'H') vert = false;
                }
                for (i = 1; i <= N; i++) {
                    if (grid[i][row] == 'H') horiz = false;
                    if (grid[row][i] == 'H') vert = false;
                }
                for (i = row; i <= N; i++) {
                    if (grid[N][i] == 'H') horiz = false;
                    if (grid[i][N] == 'H') vert = false;
                }
                sum += horiz + vert;
            }
        }
        if (K >= 3) {
            for (int row = 2; row <= N - 1; row++) {
                for (int col = 2; col <= N - 1; col++) {
                    bool horiz = true, vert = true;
                    for (i = 1; i <= row; i++) {
                        if (grid[1][i] == 'H') horiz = false;
                        if (grid[i][1] == 'H') vert = false;
                    }
                    for (i = 1; i <= col; i++) {
                        if (grid[i][row] == 'H') horiz = false;
                        if (grid[row][i] == 'H') vert = false;
                    }
                    for (i = row; i <= N; i++) {
                        if (grid[col][i] == 'H') horiz = false;
                        if (grid[i][col] == 'H') vert = false;
                    }
                    for (i = col; i <= N; i++) {
                        if (grid[i][N] == 'H') horiz = false;
                        if (grid[N][i] == 'H') vert = false;
                    }
                    sum += horiz + vert;
                }
            }
        }
        cout << sum << "\n";
    }
}