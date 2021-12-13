/*
ID: krxnc
TASK: stampede
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

struct Event {
    int t, id;
    bool s;
    Event() : t(0), id(0), s(0) {};
    Event(int ti, int idd, bool st) : t(ti), id(idd), s(st) {};
};

bool comp(Event a, Event b) {
    if (a.t == b.t) {
        if (a.s == b.s)
            return a.id < b.id;
        else
            return a.s < b.s;
    }
    return a.t < b.t;
}

int main() {
    ofstream fout("stampede.out");
    ifstream fin("stampede.in");

    int N;
    fin >> N;
    vector<Event> ev(2 * N);
    for (int i = 0; i < N; i++) {
        int x, y, r;
        fin >> x >> y >> r;
        // Travel a distance of 1 in r time.
        // Should be first visible when left edge is on -1.
        // Moves the left edge right by 1
        int start = (-x - 1) * r;
        ev[2 * i] = Event(start, y, true);
        ev[2 * i + 1] = Event(start + r, y, false);
    }
    sort(ev.begin(), ev.end(), comp);

    set<int> found;
    set<int> active;
    int c = 0;
    for (int index = 0; index < 2 * N;) {
        auto k = ev[index];
        // Update all ev[index].t in the active set
        while (index < 2 * N && ev[index].t == k.t) {
            if (ev[index].s)
                active.insert(ev[index].id);
            else
                active.erase(ev[index].id);
            index++;
        }
        // If it is the first, it can be seen
        if (active.size())
            found.insert(*active.begin());
    }
    fout << found.size() << endl;
}

/*
Farmer John's N cows (1 <= N <= 50,000) appear to be stampeding along
the road at the front of FJ's farm, but they are actually just running
in a foot race to see which cow is the fastest.

Viewed from above, each cow is represented by a unit-length horizontal
line segment, specified by the coordinates of its left corner point at
time t=0.  For example, (-3,6) would specify a cow who at time t=0 is           
represented by the segment from (-3,6) to (-2,6).  Each cow is moving to
the right (in the +x direction) at a certain rate, specified by the
integer amount of time it takes her to move 1 unit to the right.

FJ is not particularly thrilled that his cows are outside running
instead of in the barn producing milk.  He plans to admonish them with
a stern lecture after the race ends.  In order to determine which of
his cows are participating in the race, FJ situates himself at (0,0)
and looks along a ray extending in the +y direction.  As the race
unfolds, FJ sees a cow if she is ever the first cow visible along this
ray.  That is, a cow might not be visible if another cow is "in front"
of her during the entire time she crosses FJ's line of sight.

Please compute the number of cows FJ can see during the entire race.

INPUT: (file stampede.in)

The first line of the input contains N.  Each of the following N lines
describes a cow with three integers x y r, corresponding to a cow
whose left endpoint is at (x,y) at time t=0, moving to the right at a
continuous speed of 1 unit of distance every r units of time.  The
value of x is in the range -1000..-1, the value of y is in the range
1..1,000,000 (and distinct for every cow, to prevent any possible
collisions), and the value of r is in the range 1..1,000,000.

SAMPLE INPUT:

N
X Y r,   (x,y) is the left endpoint. r is the time to move a unit 
        - Cows are a 1 unit long segment

3
-2 1 3
-3 2 3
-5 100 1


OUTPUT: (file stampede.out)

A single integer, specifying the number of cows FJ can see during the
entire race (from t=0 onward).

SAMPLE OUTPUT:

2

SOLUTION NOTES:

FJ can see cows 1 and 2 but not cow 3.
C--C--C.......
..............
..............
..............
..............
...CCCC.......
..CCCC........
.....F........
  ^
*/

/*
Sweep line algorithm on intervals
*/