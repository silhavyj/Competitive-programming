#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, ans=0;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		if (a[i-1]>a[i]) {
			ans += a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout << ans << "\n";
	return 0;
}
