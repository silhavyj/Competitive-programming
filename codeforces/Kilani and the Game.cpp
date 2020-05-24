#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3;
const int MAX_P = 9;
char grid[MAX][MAX];
int speed[MAX_P];
vector<set<pair<int,int>>> players(MAX_P);
vector<int> res(MAX_P);
int moves[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, p;
	char c;
	bool over = false;
	bool poss;
	cin >> n >> m >> p;
	for (int i = 0; i < p; i++)
		cin >> speed[i];
		
	for (int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> c;
			if (c >= '1' && c <= '9') {
				players[c-'1'].insert({i,j});
				res[c-'1']++;
			}
			grid[i][j] = c;
		}
		
	while (!over) {
		over = true;
		for (int i = 0; i < p; i++) {
			poss = true;
			for (int j = 0; j < speed[i] && poss; j++) {
				set<pair<int,int>> next;
				poss = false;
				for (auto pos : players[i]) {
					for (int k = 0; k < 4; k++) {
						int y = pos.first + moves[k][0];
						int x = pos.second + moves[k][1];
						if (y < 0 || x < 0 || y >= n || x >= m)
							continue;
						if (grid[y][x] == '.') {
							over = false;
							poss = true;
							grid[y][x] = '1'+i;
							next.insert({y,x});
							res[i]++;
						}
					}
				}
				players[i] = next;
			}
		}
	}
	for (int i = 0; i < p; i++) {
		cout << res[i];
		if (i < p-1)
			cout << " ";
	}
	cout << "\n";	
	return 0;
}
