#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	ll n,m,k;
	cin >> n >> m >> k;
	ll a[n], b[m];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a,a+n);
	sort(b,b+m);
	int ans = 0;
	for (int i=0, j=0; i<n; i++) {
		while (j<m) {
			if (a[i]>=b[j]) {
				if (a[i]-b[j]<=k) {
					ans++;
					j++;
					break;
				}
				j++;
			}
			else {
				if (b[j]-a[i]<=k) {
					ans++;
					j++;
				}
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
