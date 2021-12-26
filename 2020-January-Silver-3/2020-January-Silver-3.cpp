/*
ID: krxnc
TASK: wormsort
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

vector<int> adj[100001];
int p[100001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ofstream fout("wormsort.out");
    ifstream fin("wormsort.in");

    int N, M;
    fin >> N >> M;

    for (int i = 1; i <= N; i++) 
        fin >> p[i];
    
    for (int i = 1; i <= M; i++) {

    }


    return 0;
}