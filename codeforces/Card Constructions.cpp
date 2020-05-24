#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, n;
	ll cards;
	ll l,r,m;
	int ans;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		ans = 0;
		while (n >= 2) {
			l=1;
			r=1000021509;
			//r = 10;
			//cout << n << endl;
			
			while (1) {
				if (l+1 == r)
					break;
				m = l+(r-l)/2;
				cards = 2*((m*(1+m))/2)+((m-1)*(m))/2;
				if (n > cards)
					l = m;
				else r = m;
				
			}
					
			int cards_l = (2*((l*(1+l))/2)+((l-1)*(l))/2);
			int cards_r = (2*((r*(1+r))/2)+((r-1)*(r))/2);
			
			//cout << cards_l << " " << cards_r << endl;
			
			if (n >= cards_r) 
				n -= cards_r;
			else n -= cards_l;
			ans++;

			//cout << n << endl;
		}
		//cout << "endl";
		cout << ans << "\n";
	}
	return 0;
}
