#include <bits/stdc++.h>
using namespace std;

void solve() {
	int y = 0, x = 0;
	int time = 0;
	set<pair<pair<int,int>,pair<int,int>>> visited;
	string path;
	
	cin >> path;
	for (char dir : path) {
		pair<pair<int,int>,pair<int,int>> move;
		switch(dir) {
			case 'S': {
				move = {{y,x},{y+1,x}};  
				y++; 
				break;
			}
			case 'N': {
				move = {{y-1,x},{y,x}}; 
				y--; 
				break;
			}
			case 'W': {
				move = {{y,x},{y,x-1}}; 
				x--; 
				break;
			}
			case 'E': {
				move = {{y,x+1},{y,x}}; 
				x++; 
				break;
			}
		}
		if (visited.find(move) == visited.end()) {
			visited.insert(move);
			time += 5;
		}
		else time += 1;
	}
	cout << time << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
