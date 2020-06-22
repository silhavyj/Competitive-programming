#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, x, ans=0, sum=0;
	ll neg = INT_MIN;
	bool pos = false;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x > 0)
			pos = true;
		else neg = max(neg,x);
		sum = max(sum+x, 0LL);
		ans = max(ans, sum);
	}
	if (pos)
		cout << ans << "\n";
	else cout << neg << "\n";
	return 0;
}
