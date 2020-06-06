#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int n,k,ans=0;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		ans += a[i]>=a[k-1] && a[i]>0;
	cout << ans << "\n";
	return 0;
}
