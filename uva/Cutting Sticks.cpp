#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 52;
int cuts[N];
int l,n;
int dp[N][N];

int solve(int l, int r) {
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l+1 == r)
		return 0;
	int ans = INT_MAX;
	for (int i = l+1; i < r; i++)
		ans = min(ans,cuts[r]-cuts[l]+solve(l,i)+solve(i,r));
	dp[l][r] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> l;
	while (l!=0) {
		cin >> n;
		cuts[0]=0;
		cuts[n+1]=l;
		for (int i = 0; i < n; i++)
			cin >> cuts[i+1];
		memset(dp,-1,sizeof(dp));
		cout << "The minimum cutting is " << solve(0,n+1) << ".\n";
		cin >> l;
	}		
	return 0;
}
