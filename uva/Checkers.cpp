#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100;
const int MOD = 1e6+7;
string m[N];
int dp[N][N];
int n;
int moves[2][2] = {
	{-1,1},
	{-1,-1}
};

int dfs(int y, int x) {
	if (dp[y][x] != -1)
		return dp[y][x];
	if (y == 0)
		return 1;
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		int yy = y + moves[i][0];
		int xx = x + moves[i][1];
		if (yy < 0 || xx < 0 || yy >= n || xx >= n)
			continue;
		if (m[yy][xx] == '.')
			ans += dfs(yy,xx) % MOD;
		else if (m[yy][xx] == 'B') {
			yy = y + 2*moves[i][0];
			xx = x + 2*moves[i][1];
			if (yy < 0 || xx < 0 || yy >= n || xx >= n)
				continue;
			if (m[yy][xx] == '.')
				ans += dfs(yy,xx) % MOD;
		}
	}
	dp[y][x] = ans % MOD;
	return dp[y][x];
}

void solve() {
	int y,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		for (int j = 0; j < n; j++) {
			if (m[i][j] == 'W')
				y=i, x=j;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout << dfs(y,x) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case " << i << ": ";
		solve();
	}
	return 0;
}
