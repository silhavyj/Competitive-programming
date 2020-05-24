#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Conn {
	int v, x;
	bool train;
	Conn(int _v, int _x, bool _train) : v(_v), x(_x), train(_train){}
};

const int MAX = 1e5;

vector<Conn> adj[MAX];
bool used[MAX];
ll ranks[MAX];
unordered_set<int> needed;
int n, m, k;
int u, v, x;
int s, y;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
		
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> x;
		u--, v--;
		adj[u].push_back(Conn(v,x,0));
		adj[v].push_back(Conn(u,x,0));
	}
	for (int i = 0; i < k; i++) {
		cin >> s >> y;
		s--;		
		adj[0].push_back(Conn(s,y,1));
		adj[s].push_back(Conn(0,y,1));
	}
	for (int i = 0; i < n; i++) {
		ranks[i] = INT_MAX;
		used[i] = false;
	}
		
	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
	ranks[0] = 0;
	que.push({0,0});
	while (!que.empty()) {
		auto top = que.top();
		que.pop();
		if (used[top.second])
			continue;
		used[top.second] = true;
		for (auto next : adj[top.second]) {
			if ((ranks[next.v] > top.first + next.x) || (ranks[next.v] >= top.first + next.x && !next.train)) {
				ranks[next.v] = top.first + next.x;
				que.push({top.first+next.x,next.v});
				if (top.second == 0 && next.train)
					needed.insert(next.v);
				else needed.erase(next.v);
			}
		}
	}
	cout << (k-needed.size()) << "\n";
	return 0;	
}
