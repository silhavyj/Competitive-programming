#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b, c;
	bool exists = false;
	list<int> ans;
	cin >> n >> m;
	
	int ranks[n], path[n];
	bool visited[n];
	
	for (int i = 0; i < n; i++)
		ranks[i] = INT_MAX, visited[i] = 0;
			
	vector<list<pair<int,int>>> g(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que; 
	que.push(make_pair(0,0));
		
	path[0] = -1;
	ranks[0] = 0;
	
	while (!que.empty()) {
		auto top = que.top();
		que.pop();
		int t = top.second;
		if (t == n-1) {
			int count=0;
			while (t != -1) {
				ans.push_front(t+1);
				t = path[t];
				count++;
			}
			for (int p : ans) {
				cout << p;
				if (--count)
					cout << " ";
			}
			cout << "\n";
			exists = 1;
			break;
		}
		visited[t] = 1;
		for (auto n : g[t])
			if (!visited[n.first]) {
				int w = ranks[t] + n.second;
				if (w < ranks[n.first]) {
					ranks[n.first] = w;
					path[n.first] = t;
					que.push(make_pair(w,n.first));
				}
			}
 	}
 	if (!exists)
 		cout << "-1\n";
	return 0;
}
