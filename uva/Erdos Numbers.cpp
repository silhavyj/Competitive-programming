#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int p, q, id=0, s;
	string line, name, surname, full;
	unordered_map<string,int> mp;
	unordered_map<int,int> ans;
	vector<vector<int>> work;
	cin >> p >> q;
	
	cin.ignore();
	for (int i = 0; i < p; i++) {
		getline(cin, line);
		string line2="";
		for (char c : line) {
			if (c==':')
				break;
			else if (c!=' ') {
				if (c==',')
					line2+=' ';
				else line2+=c;
			}
		}
		stringstream ss(line2);
		vector<int> paper;
		while (ss >> name >> surname) {
			full = name + ", " + surname;
			if (mp.find(full) == mp.end())
				mp[full]=id++;
			paper.push_back(mp[full]);
		}
		work.push_back(paper);
	}
	vector<list<int>> adj(mp.size());
	for (int i = 0; i < work.size(); i++)
		for (int j = 0; j < work[i].size(); j++)
			for (int k = 0; k < work[i].size(); k++) {
				adj[work[i][j]].push_back(work[i][k]);
				adj[work[i][k]].push_back(work[i][j]);
			}
	queue<int> que;
	que.push(mp["Erdos, P."]);
	ans[mp["Erdos, P."]] = 0;
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		for (int next : adj[t])
			if (ans.find(next) == ans.end()) {
				ans[next] = ans[t] + 1;
				que.push(next);
			}
	}
	for (int i = 0; i < q; i++) {
		getline(cin,name);
		cout << name << " ";
		if (mp.find(name)==mp.end() || ans.find(mp[name])==ans.end())
			cout << "infinity\n";
		else cout << ans[mp[name]] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Scenario " << i << "\n";
		solve();
	}
	return 0;
}
