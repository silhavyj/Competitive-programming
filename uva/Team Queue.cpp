#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int t) {
	int n,x,team;
	string cmd;
	unordered_map<int,int> mp;
	list<queue<int>> que;
	unordered_map<int,list<queue<int>>::iterator> pos;
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			mp[x]=i;
		}
	}
	while (1) {
		cin >> cmd;
		if (cmd == "STOP")
			break;
		else if (cmd == "ENQUEUE") {
			cin >> x;
			team = mp[x];
			if (pos.find(team)==pos.end()) {
				queue<int> q;
				q.push(x);
				que.push_back(q);
				pos[team] = que.end();
				pos[team]--;
			}
			else pos[team]->push(x);
		}
		else if (cmd == "DEQUEUE") {
			x = que.begin()->front();
			que.begin()->pop();
			if (que.begin()->empty()) {
				que.erase(que.begin());
				pos.erase(mp[x]);
			}
			cout << x << "\n";
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,s=1;
	cin >> t;
	while (t!=0) {
		cout << "Scenario #" << s << "\n";
		solve(t);
		s++;
		cin >> t;
	}	
	return 0;
}
