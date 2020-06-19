#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll s=0, ans=INT_MAX;
int a[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], s+=a[i];

	for (int i = 0; i < 1<<n; i++) {
		ll sum = 0;
		for (int j = 0; j < n; j++)
			if (i&(1<<j))
				sum += a[j];
		ans = min(ans, abs(sum-(s-sum)));
	}
	cout << ans << "\n";
	return 0;
}
