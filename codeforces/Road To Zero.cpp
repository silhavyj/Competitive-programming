#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll x,y,a,b;
		ll c1=0, c2=0;
		
		cin >> x >> y >> a >> b;
		c1 = (x+y)*a;
		ll low = min(x,y);
		ll high = max(x,y);
		c2 = low*b+(high-low)*a;
		cout << min(c1,c2) << "\n";
	}
	return 0;
}
