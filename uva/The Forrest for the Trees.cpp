#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[26];
bool visited[26];

int dfs(int x) {
	visited[x]=true;
	int ans = 1;
	for (int y : adj[x])
		if (!visited[y])
			ans += dfs(y);
	return ans;
}

void solve() {
	int tree = 0;
	int acorn = 0;
	string l;
	list<int> nodes;
	for (int i = 0; i < 26; i++){
		visited[i]=false;
		adj[i].clear();
	}
	while (1) {
		getline(cin,l);
		if (l[0]=='*')
			break;
		adj[l[1]-'A'].push_back(l[3]-'A');
		adj[l[3]-'A'].push_back(l[1]-'A');
	}
	getline(cin,l);
	for (int i = 0; i < l.length(); i+=2)
		nodes.push_back(l[i]-'A');
	for (int n : nodes)
		if (visited[n]==false) {
			if (dfs(n)==1)
				acorn++;
			else tree++;
		}
	printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
		solve();
	return 0;
}
