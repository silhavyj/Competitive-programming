#include <bits/stdc++.h>
#define ll long long
using namespace std;

int moves[4][2] = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

void solve() {
	int n,m;
	cin >> n >> m;
	int ranks[n*m];
	int mp[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			ranks[i*m+j]=INT_MAX;
			cin >> mp[i][j]; 
		}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	ranks[0]=mp[0][0];
	que.push({mp[0][0],0});
	while (!que.empty()) {
		auto t = que.top();
		que.pop();
		if (t.second==n*m-1)
			break;
		int y = t.second / m;
		int x = t.second % m;
		for (int i = 0; i < 4; i++) {
			int yy = y + moves[i][0];
			int xx = x + moves[i][1];
			if (yy < 0 || xx < 0 || yy >= n || xx >= m)
				continue;
			int d = t.first + mp[yy][xx];
			if (d < ranks[yy*m+xx]) {
				ranks[yy*m+xx] = d;
				que.push({d,yy*m+xx});
			}
		}
	}
	cout << ranks[n*m-1] << "\n";
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
