#include <bits/stdc++.h>
#define ll long long
using namespace std;

int moves[8][2] = {
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1}
};

void solve() {
	vector<string> mp;
	string line;
	pair<int,int> s;
	while(1) {
		getline(cin,line);
		if (line[0]=='_')
			break;
		for (int i = 0; i < line.length(); i++)
			if (line[i]=='*') {
				s = {mp.size(),i};
				break;
			}
		mp.push_back(line);
	}
	queue<pair<int,int>> que;
	que.push(s);
	mp[s.first][s.second]='#';
	while (!que.empty()) {
		auto t = que.front();
		que.pop();
		for (int i = 0; i < 8; i++) {
			int yy = t.first + moves[i][0];
			int xx = t.second + moves[i][1];
			if (yy < 0 || xx < 0 || yy >= mp.size() || xx >= mp[yy].size())
				break;
			if (mp[yy][xx]==' ') {
				mp[yy][xx]='#';
				que.push({yy,xx});
			}
		}
	}
	for (int i = 0; i < mp.size(); i++) {
		for (int j = 0; j < mp[i].size(); j++)
			cout << mp[i][j];
		cout << endl;
	}
	cout << line << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string line;
	int t;
	cin >> t;
	getline(cin,line);
	while (t--)
		solve();
	return 0;
}
