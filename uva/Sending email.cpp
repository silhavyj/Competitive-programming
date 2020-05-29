#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n,m,s,t;
	int a,b,w,d;
	cin >> n >> m >> s >> t;
	vector<list<pair<int,int>>> adj(n);
	int ranks[n];
	for (int i = 0; i < n; i++)
		ranks[i]=INT_MAX;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	que.push({0,s});
	ranks[s]=0;
	while (!que.empty()) {
		auto top = que.top();
		que.pop();
		if (top.second==t) {
			cout << ranks[t] << "\n";
			return;
		}
		for (auto x : adj[top.second]) {
			d = top.first + x.second;
			if (d < ranks[x.first]) {
				ranks[x.first]=d;
				que.push({d,x.first});
			}
		}
	}
	cout << "unreachable\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
