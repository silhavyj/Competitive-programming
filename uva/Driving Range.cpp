#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6;
int n,m,a,b,c;
int par[N];
int ranks[N];

int find(int x) {
	return par[x] == x ? x : (par[x] = find(par[x]));
}

void merge(int px, int py) {
	if (ranks[px] < ranks[py])
		par[px] = py;
	else {
		par[py] = px;
		if (ranks[px] == ranks[py])
			ranks[px]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	vector<pair<int,pair<int,int>>> edges;
	while (n || m) {
		edges.clear();
		for (int i = 0; i < n; i++)
			par[i]=i, ranks[i]=1;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			edges.push_back({c,{a,b}});
		}
		sort(edges.begin(),edges.end());
		int conn=0, ans=0;
		for (auto e : edges) {
			a = find(e.second.first);
			b = find(e.second.second);
			if (a != b) {
				ans = max(ans, e.first);
				merge(a,b);
				conn++;
				if (conn == n-1)
					break;
			}
		}
		if (conn != n-1)
			cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
		cin >> n >> m;
	}	
	return 0;
}
