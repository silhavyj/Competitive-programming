#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int n;
	cin >> n;
	int ans[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans[x-1]=i+1;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
