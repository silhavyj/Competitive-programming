#include <bits/stdc++.h>
#define ll long long
using namespace std;

int moves[4][2] = {
	{-1,0},
	{1,0},
	{0,1},
	{0,-1}
};

void solve(int r, int c) {
	int n,y,x,s,e;
	unordered_set<int> bombs;
	unordered_map<int,int> step;
	int col;
	cin >> col;
	for (int i = 0; i < col; i++) {
		cin >> y >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			bombs.insert(y*c+x);
		}
	}
	cin >> y >> x, s=y*c+x;
	cin >> y >> x, e=y*c+x;
	queue<int> que;
	que.push(s);
	step[s]=0;
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		if (t==e) {
			cout << step[t] << "\n";
			return;
		}
		y = t / c;
		x = t % c;
		for (int i = 0; i < 4; i++) {
			int yy = y + moves[i][0];
			int xx = x + moves[i][1];
			if (yy < 0 || xx < 0 || yy >= r || xx >= c)
				continue;
			int v = yy*c+xx;
			if (step.find(v) != step.end() || bombs.find(v) != bombs.end())
				continue;
			step[v] = step[t]+1;
			que.push(v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int r,c;
	cin >> r >> c;
	while (r || c) {
		solve(r,c);
		cin >> r >> c;
	}
	return 0;
}
