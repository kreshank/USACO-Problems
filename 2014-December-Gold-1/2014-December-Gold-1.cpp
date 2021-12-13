/*
ID: krxnc
TASK: guard
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int H[21], W[21], S[21];

int main() {
    ofstream fout("guard.out");
    ifstream fin("guard.in");

    int N, M;
    fin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> W[i] >> S[i];
    }

    return 0;
}

/*
Problem 1: Guard Mark [Bill Cooperman, 2014]

Farmer John and his herd are playing frisbee.  Bessie throws the
frisbee down the field, but it's going straight to Mark the field hand
on the other team!  Mark has height H (1 <= H <= 1,000,000,000), but
there are N cows on Bessie's team gathered around Mark (2 <= N <= 20).
They can only catch the frisbee if they can stack up to be at least as
high as Mark.  Each of the N cows has a height, weight, and strength.
A cow's strength indicates the maximum amount of total weight of the
cows that can be stacked above her.

Given these constraints, Bessie wants to know if it is possible for
her team to build a tall enough stack to catch the frisbee, and if so,
what is the maximum safety factor of such a stack.  The safety factor
of a stack is the amount of weight that can be added to the top of the
stack without exceeding any cow's strength.

INPUT: (file guard.in)

The first line of input contains N and H.

The next N lines of input each describe a cow, giving its height,
weight, and strength.  All are positive integers at most 1 billion.

SAMPLE INPUT:

4 10
9 4 1
3 3 5
5 5 10
4 4 5

OUTPUT: (file guard.out)

If Bessie's team can build a stack tall enough to catch the frisbee,
please output the maximum achievable safety factor for such a stack.
Otherwise output "Mark is too tall" (without the quotes).

SAMPLE OUTPUT:

2
*/

/*
Thoughts:
Since N <= 20, even an N^6 solution is fine.
*/