/*
ID: krxnc
TASK: Acowdemia III
LANG: C++
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };
char arr[1002][1002];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(arr, ' ', sizeof(arr));
    cin >> N >> M;

    cin.ignore();

    for (int i = 1; i <= N; i++) cin >> arr[i] + 1;

    set<vector<pii>> pairs;

    int count = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (arr[i][j] == 'G') {
                vector<pii> pp;
                for (int k = 0; k < 4; k++)
                    if (arr[i + dx[k]][j + dy[k]] == 'C')
                        pp.push_back({ i + dx[k],j + dy[k] });

                if (pp.size() == 2) {
                    sort(pp.begin(), pp.end());
                    pairs.insert(pp);
                }
                else if (pp.size() > 2) {
                    count++;
                }
            }

    cout << count + pairs.size() << "\n";
}