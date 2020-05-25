#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<list<int>>& adj, bool *seen, int x) {
	seen[x]=true;
	for (int y : adj[x])
		if (seen[y]==false)
			dfs(adj, seen, y);
}

void solve() {
	string line;
	int ans=0;
	getline(cin,line);
	int n = line[0]-'A'+1;
	bool seen[n];
	vector<list<int>> adj(n);
	while (1) {
		getline(cin,line);
		if (line == "")
			break;
		adj[line[0]-'A'].push_back(line[1]-'A');
		adj[line[1]-'A'].push_back(line[0]-'A');
	}
	memset(seen, false, sizeof(seen));
	for (int i = 0; i < n; i++)
		if (seen[i]==false) {
			ans++;
			dfs(adj,seen,i);
		}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	string line;
	cin >> t;
	cin.ignore();
	getline(cin,line);
	while (t--) {
		solve();
		if (t!=0)
			cout << "\n";
	}
	return 0;
}
