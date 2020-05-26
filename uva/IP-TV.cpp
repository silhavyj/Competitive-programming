#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2000;
int par[N], ranks[N];

int find(int x) {
	if (par[x] == x)
		return x;
	par[x] = find(par[x]);
	return par[x];
}

void uni(int px, int py) {
	if (ranks[px] < ranks[py])
		par[px] = py;
	else {
		par[py] = px;
		if (ranks[px] == ranks[py])
			ranks[px]++;
	}
}

void solve() {
	int n, m, c, id=0, ans=0;
	int px, py;
	string a, b;
	unordered_map<string, int> mp;
	vector<pair<int,pair<int,int>>> edges;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		par[i]=i, ranks[i]=1;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (mp.find(a) == mp.end()) mp[a]=id++;
		if (mp.find(b) == mp.end()) mp[b]=id++;
		edges.push_back({c,{mp[a],mp[b]}});
	}
	sort(edges.begin(),edges.end());
	for (auto e : edges) {
		px = find(e.second.first);
		py = find(e.second.second);
		if (px != py) {
			uni(px,py);
			ans += e.first;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		solve();
		if (t)
			cout << "\n";
	}
	return 0;
}
