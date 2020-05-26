#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,a,b;
double p;

void solve() {
	vector<list<pair<int,double>>> adj(n);
	priority_queue<pair<double,int>> que;
	double rank[n];
	
	for (int i = 0; i < n; i++)
		rank[i]=-1;
		
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> p;
		p /= 100.0;
		a--, b--;
		adj[a].push_back({b,p});
		adj[b].push_back({a,p});
	}
	rank[0]=1.0;
	que.push({1.0,0});
	while (!que.empty()) {
		auto t = que.top();
		que.pop();
		if (t.second == n-1)
			break;
		for (auto next : adj[t.second]) {
			double d = rank[t.second] * next.second;
			if (d > rank[next.first]) {
				rank[next.first] = d;
				que.push({d,next.first});
			}
		}
	}
	printf("%.6f percent\n", rank[n-1]*100.0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while (n) {
		cin >> m;
		solve();
		cin >> n;
	}	
	return 0;
}
