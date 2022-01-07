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
typedef pair<int, int> pii;


string zodiacs[] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
map<string, int> zid;
map<string, int> cowYear;
int N;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 12; i++) zid[zodiacs[i]] = i;

    cin >> N; cin.ignore();
    cowYear["Bessie"] = 0;

    string child, born, in, dir, zodiac, year, from, parent;
    for (int i = 0; i < N; i++) {
        cin >> child >> born >> in >> dir >> zodiac >> year >> from >> parent;

        int chZID = zid[zodiac];
        int parZID = cowYear[parent];
        int inc = (dir == "next") ? 1 : -1;

        int a = inc;
        while ((parZID + a - chZID) % 12 != 0) {
            a += inc;
        }
        cowYear[child] = parZID + a;
    }
    
    cout << abs(cowYear["Elsie"]) << "\n";
}