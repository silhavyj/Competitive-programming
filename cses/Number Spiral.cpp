#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll t, y, x, n,m, ans;
	cin >> t;
	while (t--) {
		cin >> y >> x;
		n = max(y,x);
		m = n*n;
		if ((y < x && m % 2 == 0) || (y > x && m % 2 == 1)) {
			m -= 2*(n-1);
			ans = m + min(y,x)-1;
		}
		else ans = m-min(y,x)+1;
		cout << ans << "\n";
	}
	return 0;
}
