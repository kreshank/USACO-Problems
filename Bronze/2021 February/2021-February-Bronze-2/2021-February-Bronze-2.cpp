/*
ID: krxnc
TASK: Comfortable Cows
LANG: C++
*/

#include <iostream>
using namespace std;

//Definitions
typedef pair<int, int> pii;
typedef long long ll;

int N;
int grid[1001][1001];
int neighbors[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	int x, y, comf = 0;
	for (int cowCount = 0; cowCount < N; cowCount++) {
		cin >> x >> y;
		grid[x][y] = 1;
		if (neighbors[x][y] == 3)
			comf++;

		int nx, ny;
		int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

		for (int i = 0; i < 4; i++) {
			nx = dx[i] + x;
			ny = dy[i] + y;
			if (nx < 0 || ny < 0) continue;
			if (nx >= 1000 || ny >= 1000) continue;

			int& k = neighbors[nx][ny];
			if (grid[nx][ny]) {
				if (k == 2)
					comf++;
				else if (k == 3)
					comf--;
			}
			k++;
		}

		cout << comf << "\n";
	}
}