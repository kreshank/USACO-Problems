/*
ID: krxnc
TASK: cowroute
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

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 9e18;

int A, B, N;

vector<ll> adj[1001];
ll dist[1001];
ll pre[1001];

struct compare {
    bool operator() (const int& a, const int& b) const {
        return dist[a] < dist[b];
    }
};

void dijikstra(int src) {
    set<int, compare> Q;
    for (int i = 0; i < 1000; i++) {
        dist[i] = INF;
        pre[i] = -1;
        Q.insert(i);
    }
    dist[src] = 0;
    while (Q.size()) {
        int u = *Q.begin();
        Q.erase(u);
        for (auto v : adj[u]) {
            int hold = dist[u] + adj[u][v];
            if (hold < dist[v]) {
                dist[v] = hold;
                pre[v] = u;
            }
        }
    }
}

int main() {
    ofstream fout("cowroute.out");
    ifstream fin("cowroute.in");

    fin >> A >> B >> N;
    
    for (int i = 0; i < N; i++) {
        int c, num;
        fin >> c >> num;
        for (int j = 0; j < num; j++) {

        }
    }
}

/*
Air Bovinia owns N planes (1 <= N <= 1000), each of which flies on a
specific "route" consisting of two or more cities.  For example, one
plane might fly on a route that starts at city 1, then flies to city
5, then flies to city 2, and then finally flies to city 8.  No city
appears multiple times in a route.  If Bessie chooses to utilize a
route, she can board at any city along the route and then disembark at
any city later along the route.  She does not need to board at the
first city or disembark at the last city.  Each route has a certain
cost, which Bessie must pay if she uses any part of the route,
irrespective of the number of cities she visits along the route.  If
Bessie uses a route multiple times during her travel (that is, if she
leaves the route and later comes back to use it from another city),
she must pay for it each time it is used.

Bessie would like to find the cheapest way to travel from her farm
(in city A) to her tropical destination (city B). Decide what is the 
minimum cost she must pay, and also the smallest number of individual 
flights she must use take to achieve this minimum cost.

INPUT: (file cowroute.in)

The first line of input contains A, B, and N, separated by spaces.

The next 2N lines describe the available routes, in two lines per
route. The first line contains the cost of using the route (an integer
in the range 1..1,000,000,000), and the number of cities along the
route (an integer in the range 1..100).  The second line contains a
list of the cities in order along the route.  Each city is identified
by an integer in the range 1..1000.  Note that the cost of an
itinerary can easily add up to more than can fit into a 32-bit
integer, so you should probably use 64-bit integers (e.g., "long long"
integers in C/C++).

SAMPLE INPUT:

Max cities = 100

A (Start city) B (End city) N (Num of planes routes)
C (cost of route) M (num of stops in the route, min 2)

3 4 3
3 5
1 2 3 4 5
2 3
3 5 4
1 2
1 5

OUTPUT: (file cowroute.out)

Output the minimum cost of an itinerary that Bessie can use to travel
from city A to city B, as well as the minimum number of individual
flights required to achieve this minimum cost.  If there is no
solution, output "-1 -1" (quotes for clarity) on a single line.

SAMPLE OUTPUT:

2 2
*/

/*
Looks like a dp/BFS problem

Maybe dijikstra?
*/