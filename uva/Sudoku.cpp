#include <bits/stdc++.h>
#define ll long long
using namespace std;

string mps[4];
int mp[4][4];
bool done;
vector<pair<int,int>> s;

bool ok(int y, int x, int v) {
	for (int i = 0; i < 4; i++)
		if ((i!=y && mp[i][x]==v) || (i!=x && mp[y][i]==v))
			return false;
	int yy = y & 1 ? y-1 : y+1;
	int xx = x & 1 ? x-1 : x+1;
	return mp[yy][xx] != v;
}

void solve(int k) {
	if (k==s.size()) {
		done = true;
		return;
	}
	for (int v = 1; v <= 4; v++) {
		int y = s[k].first;
		int x = s[k].second;
		if (ok(y,x,v)) {
			mp[y][x]=v;
			solve(k+1);
			if (done)
				return;
			mp[y][x]=0;
			
		}
	}
}

void solve() {
	s.clear();
	for (int i = 0; i < 4; i++) {
		getline(cin,mps[i]);
		for (int j = 0; j < 4; j++) {
			if (mps[i][j]=='*')
				s.push_back({i,j});
			mp[i][j] = mps[i][j]=='*' ? 0 : mps[i][j]-'0';
		}
	}
	done=false;
	solve(0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << mp[i][j];
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string blank;
	int t;
	cin >> t;
	cin.ignore();
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":\n";
		getline(cin,blank);
		solve();
	}
	return 0;
}
