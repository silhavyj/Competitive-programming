#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3;
string mp[N];
int d[N][N];
int n,m,len;
int sy,sx;

int moves[4][2] = {
	{-1,0},
	{1,0},
	{0,1},
	{0,-1}
};

void dfs(int y, int x, int s) {
	d[y][x] = s;
	if (s > len) {
		len = s;
		sy = y;
		sx = x;
	}
	for (int i = 0; i < 4; i++) {
		int yy = y + moves[i][0];
		int xx = x + moves[i][1];
		if (yy < 0 || xx < 0 || yy >= n || xx  >= m)
			continue;
		if (mp[yy][xx]=='#' || d[yy][xx]!=-1)
			continue;
		dfs(yy,xx,s+1);
	}
}

void solve() {
	int ans=0;
	vector<pair<int,int>> pos;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> mp[i];
		for (int j = 0; j < m; j++) {
			if (mp[i][j]=='.')
				pos.push_back({i,j});
		}
	}
	memset(d,-1,sizeof(d)); 
	len = 0;
	dfs(pos[0].first, pos[0].second, 0);
	ans = max(ans, len);
	memset(d,-1,sizeof(d)); 
	len = 0;
	dfs(sy, sx, 0);
	ans = max(ans, len);
	cout << "Maximum rope length is " << ans << ".\n";
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
