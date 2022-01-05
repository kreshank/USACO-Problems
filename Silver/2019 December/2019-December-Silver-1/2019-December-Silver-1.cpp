/*
ID: krxnc
TASK: moobuzz
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

typedef long long ll;

using namespace std;

vector<ll> a = { 0,1,2,4,7,8,11,13,14 };

ll num(ll n) {
    ll quo = (n - 1) / 8;
    ll rem = n - quo * 8;
    return quo * 15 + a[rem];
}

int main() {
    ofstream fout("moobuzz.out");
    ifstream fin("moobuzz.in");

    ll N;
    fin >> N;

    ll x = num(N);
    fout << x << endl;
    fout.close();
}

/*
Farmer John's cows have recently become fans of playing a simple number game called "FizzBuzz". 
The rules of the game are simple: standing in a circle, the cows sequentially count upward from one, 
each cow saying a single number when it is her turn. If a cow ever reaches a multiple of 3, 
however, she should say "Fizz" instead of that number. If a cow reaches a multiple of 5, 
she should say "Buzz" instead of that number. If a cow reaches a multiple of 15, she should 
say "FizzBuzz" instead of that number. A transcript of the first part of a game is therefore:

1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16

Having a slightly more limited vocabulary, the version of FizzBuzz played by the cows involves saying "Moo" instead of Fizz, Buzz, and FizzBuzz. The beginning of the cow version of the game is therefore

 1,  2, Moo,  4, Moo, Moo, 7,   8, Moo, Moo, 11, Moo, 13, 14, Moo,    -> 8 per row ->  1 -> 8  = 0
16, 17, Moo, 19, Moo, Moo, 22, 23, Moo, Moo, 26, Moo, 28, 29, Moo,    -> 8 per row ->  9 -> 16 = 1


12 th number -> 22
12 / 9 = 1
12 % 9 = 3
15 + 4

Given N (1≤N≤10^9), please determine the Nth number spoken in this game.

SCORING
Test cases 2-5 satisfy N≤10^6.
INPUT FORMAT (file moobuzz.in):
The input consists of a single integer, N.
OUTPUT FORMAT (file moobuzz.out):
Please print out the Nth number spoken during the game.
SAMPLE INPUT:
4
SAMPLE OUTPUT:
7
The 4th number spoken is 7. The first 4 numbers spoken are 1, 2, 4, 7, since we skip over any time a cow says "Moo"
*/