#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n, ans=0;
	bool done;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n-1; i++) {
		done = true;
		for (int j = 0; j < n-i-1; j++)
			if (a[j] > a[j+1]) {
				done = false;
				swap(a[j],a[j+1]);
				ans++;
			}
		if (done)
			break;
	}
	printf("Optimal train swapping takes %d swaps.\n", ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
