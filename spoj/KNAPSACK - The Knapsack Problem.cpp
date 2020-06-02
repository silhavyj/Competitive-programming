#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int s,n,a,b;
	cin >> s >> n;
	int dp[n+1][s+1];
	vector<pair<int,int>> items;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		items.push_back({a,b});
	}
	sort(items.begin(), items.end());
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < s+1; j++) {
			if (j < items[i-1].first)
				dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], items[i-1].second + dp[i-1][j-items[i-1].first]);
		}
	cout << dp[n][s] << "\n";
	return 0;
}
