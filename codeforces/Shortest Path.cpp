#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int n, int m, int k) {
	vector<int> adj[n];
	map<pair<int,int>, set<int>> forbidden;
	int d[n][n];
	int from[n][n];
	int dis,u,v;
	int a,b,c;
	bool found=false;
	vector<int> ans;
	int y,x,t;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c;
		a--, b--, c--;
		forbidden[{a,b}].insert(c);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			d[i][j] = INT_MAX;
			from[i][j] = -1;
		}

	queue<tuple<int,int,int>> que;
	que.emplace(0,0,0);
	d[0][0] = 0;
	while (!que.empty()) {
		tie(dis,u,v) = que.front();
		que.pop();
		if (v == n-1) {
			found = true;
			break;
		}
		for (auto w : adj[v]) {
			if (forbidden.find({u,v}) != forbidden.end() &&
				forbidden[{u,v}].find(w) != forbidden[{u,v}].end())
				continue;
			if (d[v][w] > d[u][v] + 1) {
				d[v][w] = d[u][v] + 1;
				from[v][w] = u;
				que.emplace(d[v][w], v, w);
			}
		}
	}
	if (!found)
		cout << "-1\n";
	else {
		y = x = n-1;
		for (int i = 0; i < n; i++)
			if (d[i][n-1] < d[y][n-1])
				y = i;
		while (x!=-1 && y!=-1) {
			ans.insert(ans.begin(),x+1);
			t = from[y][x];
			x = y;
			y = t;
		}
		cout << (ans.size()-1) << "\n";
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i];
			if (i != (int)ans.size()-1)
				cout << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	solve(n,m,k);
	return 0;
}
