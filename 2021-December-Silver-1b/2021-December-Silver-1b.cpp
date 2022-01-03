#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> patches;

int main() {
	int K, M, N;
	cin >> K >> M >> N;

	patches.resize(K + M);

	for (int i = 0; i < K; i++) {
		cin >> patches[i].first >> patches[i].second;
	}
	for (int i = K; i < K + M; i++) {
		cin >> patches[i].first;
		patches[i].second = -1; // This is Nhoj's thing
	}
	sort(patches.begin(), patches.end());


}