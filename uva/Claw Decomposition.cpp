#include <bits/stdc++.h>
#define ll long long
using namespace std;

int v;
int clr[300];
bool ok;

void test(vector<list<int>>& adj, int x, bool c) {
	clr[x]=c;
	for (int y : adj[x]) {
		if (clr[y]==c) {
			ok = false;
			return;
		}
		else if (clr[y]==-1) {
			test(adj,y,!c);
			if (!ok)
				return;
		}
	}
}

void solve() {
	int a,b,e=0;
	vector<list<int>> adj(v);
	while (1) {
		cin >> a >> b;
		if (a==0 && b==0)
			break;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
		e++;
	}
	if (e % 3 != 0)
		cout << "NO\n";
	else {
		ok = true;
		memset(clr,-1,sizeof(clr));
		test(adj,0,0);
		cout << (ok ? "YES\n" : "NO\n");
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> v;
	while (v != 0) {
		solve();
		cin >> v;
	}
	return 0;
}
