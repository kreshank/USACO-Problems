#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

// Set of Geometric functions/structures
struct Geometry {

    struct Point {
        int x, y;
        Point() : x(0), y(0) {}
        Point(pair<int, int> a) : x(a.first), y(a.second) {}
        Point(int a, int b) : x(a), y(b) {}
        bool equals(Point p) {
            return x == p.x && y == p.y;
        }
        int manDist(Point p) const {
            return abs(p.x - x) + abs(p.y - y);
        }
        int distSq(Point p) const {
            int dx = p.x - x;
            int dy = p.y - y;
            return dx * dx + dy * dy;
        }
    };

    struct LineSegment {
        Point p1, p2;
        LineSegment() : p1(), p2() {}
        LineSegment(Point a, Point b) : p1(a), p2(b) {}
        LineSegment(int a, int b, int c, int d) : p1(Point(a, b)), p2(Point(c, d)) {}
    };
    // Gets orientation of three points
    // Returns 0 if collinear, 1 if clockwise, 2 if counterclockwise
    int orientation(Point a, Point b, Point c) {
        ll val = ((ll)b.y - (ll)a.y) * ((ll)c.x - (ll)b.x) - ((ll)c.y - (ll)b.y) * ((ll)b.x - (ll)a.x);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }
    // Check if a point q lies on segment pr
    bool onSegment(Point p, Point q, Point r) {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
            return true;

        return false;
    }
    // Check if two lines l1 and l2 intersect
    bool intersect(LineSegment l1, LineSegment l2) {
        Point p1 = l1.p1, q1 = l1.p2, p2 = l2.p1, q2 = l2.p2;
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4) return true; // general

        // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
        if (o1 == 0 && onSegment(p1, p2, q1)) return true;

        // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
        if (o2 == 0 && onSegment(p1, q2, q1)) return true;

        // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
        if (o3 == 0 && onSegment(p2, p1, q2)) return true;

        // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
        if (o4 == 0 && onSegment(p2, q1, q2)) return true;

        return false;
    }
    bool intersect(Point P1, Point P2, Point Q1, Point Q2) {
        LineSegment L1(P1, P2), L2(Q1, Q2);
        return intersect(L1, L2);
    }
    // Checks if point is inside the figure, even points and lines.
    // O(n)
    bool isInsideInclusive(Point polygon[], int N, Point p) {
        // Create a Point for line segment from p to infinite 
        Point extreme = { INT_MAX, p.y + 1 };

        // Count intersections of the above line with sides of polygon 
        int count = 0, i = 0;
        do
        {
            int N = (i + 1) % N;

            // Check if the line segment from 'p' to 'extreme' intersects 
            // with the line segment from 'polygon[i]' to 'polygon[next]' 
            if (intersect(LineSegment(polygon[i], polygon[N]), LineSegment(p, extreme)))
            {
                // If the Point 'p' is colinear with line segment 'i-next', 
                // then check if it lies on segment. If it lies, return true, 
                // otherwise false 
                if (orientation(polygon[i], p, polygon[N]) == 0)
                    return onSegment(polygon[i], p, polygon[N]);

                count++;
            }
            i = N;
        } while (i != 0);

        // Return true if count is odd, false otherwise 
        return count & 1;  // Same as (count%2 == 1) 
    }
    // Same as above, but strictly only polygons
    bool isInside(Point polygon[], int N, Point p) {
        // There must be at least 3 vertices in polygon[] 
        if (N < 3)  return false;
        return isInsideInclusive(polygon, N, p);
    }
    bool isInside(vector<Point> polygon, int N, Point p) {
        return isInside(&polygon[0], N, p);
    }
    // Gets area of a polygon
    // O(n)
    double pArea(Point polygon[], int N) {
        if (N < 3) return 0.0;
        double area = 0.0;
        int j = N - 1;
        for (int i = 0; i < N; i++) {
            Point ii = polygon[i], jj = polygon[j];
            area += ((double)jj.x + ii.x) * ((double)jj.y - ii.y);
            j = i;
        }
        return abs(area / 2.0);
    }
    double pArea(vector<Point> polygon, int N) {
        return pArea(&polygon[0], N);
    }
    // Helper comparison function for graham scan (get convex_hull)
    bool grahamComp(Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    // Graham scan implementation for finding the convex_hull
    // Is already optimal at O(nlogn)
    // Returns a vector of the vertices.
    vector<Point> convex_hull(vector<Point> a) {
        if (a.size() <= 1)
            return a;

        sort(a.begin(), a.end(), &grahamComp);
        Point p1 = a[0], p2 = a.back();
        vector<Point> up, down;
        up.push_back(p1);
        down.push_back(p1);
        for (int i = 1; i < (int)a.size(); i++) {
            if (i == a.size() - 1 || orientation(p1, a[i], p2) == 1) {
                while (up.size() >= 2 && orientation(up[up.size() - 2], up[up.size() - 1], a[i]) != 1)
                    up.pop_back();
                up.push_back(a[i]);
            }
            if (i == a.size() - 1 || orientation(p1, a[i], p2) == 2) {
                while (down.size() >= 2 && orientation(down[down.size() - 2], down[down.size() - 1], a[i]) != 2)
                    down.pop_back();
                down.push_back(a[i]);
            }
        }

        a.clear();
        for (int i = 0; i < (int)up.size(); i++)
            a.push_back(up[i]);
        for (int i = down.size() - 2; i > 0; i--)
            a.push_back(down[i]);

        return a;
    }
};

// Set of String manipulation
struct StringManips {

    // Rabin Karp algorithm for string matching
    // Returns a vector of integers naming the starting index where the pattern is found
    // O(S + T); Note that you should change p = 31 to other primes: sometimes contests
    // would try "hacking" you and put known collisions
    vector<int> rabin_karp(string& t, string& pat) {
        const int p = 31;
        const int m = 1e9 + 9;
        vector<ll> p_pow(max(t.size(), pat.size()));
        p_pow[0] = 1;
        for (int i = 1; i < p_pow.size(); i++)
            p_pow[i] = (p_pow[i - 1] * p) % m;

        vector<ll> h(t.size() + 1);
        for (int i = 0; i < t.size(); i++) {
            h[i + 1] = (h[i] + ((ll)t[i] - 'a' + 1) * p_pow[i]) % m; // Get next hash
        }
        ll hp = 0;
        for (int i = 0; i < pat.size(); i++) {
            hp = (hp + ((ll)pat[i] - 'a' + 1) * p_pow[i]) % m;
        }

        vector<int> res;
        for (int i = 0; i + pat.size() - 1 < t.size(); i++) {
            ll curH = (h[i + pat.size()] - h[i] + m) % m;
            if (curH == hp * p_pow[i] % m) {
                res.push_back(i);
            }
        }
        return res;
    }
    // Preprocess the pattern
    int b[100010];
    void kmpPreprocess(string p) { // call this before calling kmpSearch()
        int m = p.size();
        int i = 0, j = -1; b[0] = -1; // starting values
        while (i < m) { // pre-process the pattern string P
            while (j >= 0 && p[i] != p[j]) j = b[j]; // different, reset j using b
            i++; j++; // if same, advance both pointers
            b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
        }
    } // in the example of P = "SEVENTY SEVEN" above
    // Search and return all indices of starts of the pattern
    vector<int> kmpSearch(string t, string p) { // this is similar as kmpPreprocess(), but on string T
        int N = t.size();
        int m = p.size();
        vector<int> ans;
        int i = 0, j = 0; // starting values
        while (i < N) { // search through string T
            while (j >= 0 && t[i] != p[j])
                j = b[j]; // different, reset j using b
            i++; j++; // if same, advance both pointers
            if (j == m) { // a match found when j == m
                ans.push_back(i - j);
                //cout << "P is found at index " << i - j << "in T\n";
                j = b[j]; // prepare j for the next possible match
            }
        }
        return ans;
    }
    // Alternate KMP implementation
    int N[100010];
    void getnext(string T) {
        N[0] = 0;
        int i = 0, j = 1;
        while (i < T.length()) {
            if (T[i] == T[j]) {
                i++; j++;
                N[i] = j;
            }
            else j = N[j];
        }
    }
    void KMP(string S, string T) {
        int i = 0, j = 0;
        while (i < T.length()) {
            if (S[i] == T[j]) {
                i++; j++;
            }
            else j = N[j];
        }
    }
};

struct FenwickTree {
    ll tree[1 << 17];
    ll maxIDX = 1 << 17;
    ll read(int idx) {
        ll sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void update(int idx, int val) {
        while (idx <= maxIDX) {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
};

struct SegmentTree {
    // tree is 1 based, A is 0 based
    int A[1000], tree[sizeof(A) * 2], lazy[sizeof(tree)];
    // Create the tree recursively.
    // node = current node being processed
    // O(N)
    void build(int node, int start, int end) {
        if (start == end) {
            // Is leaf, can assign value
            tree[node] = A[start];
        }
        else {
            int mid = (start + end) / 2;
            // Left child
            build(2 * node, start, mid);
            // Right child
            build(2 * node + 1, mid + 1, end);
            // Step for operation (can be sum, min, max, etc.)
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    // Updates an index with the val (add on)
    // O(log n)
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // Leaf
            A[idx] += val;
            tree[node] += val;
        }
        else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                // If idx is in left child
                update(2 * node, start, mid, idx, val);
            }
            else {
                // If idx is in right child
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            // Internal nodes will have sum of both children
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    // O(log n)
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // 
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return (p1 + p2);
    }
    // Pretty much going through each possibility
    void updateRange(int node, int start, int end, int l, int r, int val) {
        // out of range
        if (start > end || start > r || end < l) {
            return;
        }
        // is leaf
        if (start == end) {
            // Add the difference to current node
            tree[node] += val;
            return;
        }

        // If not leaf, recur for children
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, val);
        updateRange(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    // Lazy propagation
    void updateRangeL(int node, int start, int end, int l, int r, int val) {
        if (lazy[node] != 0) {
            // Node needs to be updated
            tree[node] += (end - start + 1) * lazy[node]; // update
            if (start != end) {
                // Mark children as lazy
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0; // Reset
        }
        if (start > end || start > r || end < l)
            return; // Segment not in [l,r]
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[node * 2] += val;
                lazy[node * 2 + 1] += val;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRangeL(node * 2, start, mid, l, r, val);
        updateRangeL(node * 2 + 1, mid + 1, end, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};