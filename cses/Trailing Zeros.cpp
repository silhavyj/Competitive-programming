#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans=0;
	cin >> n;
	for (int i=5; n/i>=1; i*=5)
		ans += n/i;
	cout << ans << "\n";
	return 0;
}
