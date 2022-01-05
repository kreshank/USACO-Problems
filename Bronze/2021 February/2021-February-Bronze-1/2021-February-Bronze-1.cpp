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
map<string, pii> cowYear;
int N;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 12; i++) zid[zodiacs[i]] = i;

    cin >> N; cin.ignore();
    cowYear["Bessie"] = { 0,0 };

    string line[8];
    for (int i = 0; i < N; i++) {
        for (int WORD = 0; WORD < 8; WORD++) cin >> line[WORD];
        int target = zid[line[4]], calc;
        pii from = cowYear[line[7]];
        bool pre = (line[3] == "previous");
        calc = (target - from.first) % 12;
        if (pre) {
            calc = 12 - calc;
            calc %= 12;
            calc *= -1;
        }
        if (from.second == target) calc = 12;
        cowYear[line[0]] = {from.first + calc, target};
    }
    
    cout << abs(cowYear["Elsie"].first) << "\n";
}