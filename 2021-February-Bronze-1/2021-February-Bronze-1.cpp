/*
ID: krxnc
TASK: Year of the Cow
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef pair<string, string> pss;
typedef pair<pss, bool> pssi;


string zodiacs[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, int> zid;
set<string> names = { "Bessie", "Elsie" };
vector<pssi> input;
int N;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 12; i++) zid[zodiacs[i]] = i + 1;

    cin >> N; cin.ignore();
    input.resize(N);

    string s;
    pssi p;
    for (int i = 0; i < N; i++) {
        cin >> s; p.first.first = s;
        names.insert(s);
        cin >> s; cin >> s; // loop
        int pre;
        cin >> s; pre = (s == "previous") ? -1 : 1;
        cin >> s; p.second = zid[s] * pre; // {string,string,}, int; int = change from other
        cin >> s; cin >> s;
        cin >> s; p.first.second = s; // second
    }


    return 0;
}