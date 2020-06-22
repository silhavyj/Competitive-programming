#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int p[n];
	for (int i=0; i<n; ++i)
		cin >> p[i];
	sort(p,p+n);
	ll t = n&1 ? p[n/2] : (p[n/2]+p[n/2-1])/2;
	ll ans = 0;
	for (int i=0; i<n; ++i)
		ans += abs(p[i]-t);
	cout << ans << "\n";
	return 0;
}
