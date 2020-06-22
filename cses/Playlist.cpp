#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n;
	map<int,int> mp;
	int ans=0, s=0;
	for (int i=0; i<n; ++i) {
		cin >> x;
		if (mp.find(x)!=mp.end() && mp[x]>=s)	
			s=mp[x]+1;
		ans=max(ans,i-s+1);
		mp[x]=i;
	}
	cout << ans << "\n";
	return 0;
}
