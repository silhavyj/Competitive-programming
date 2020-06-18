#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	cin >> n;
	ll s = (n*(1+n))/2;
	if (s & 1)
		cout << "NO\n";
	else {
		cout << "YES\n";
		ll t=0;
		vector<bool> u(n,false);
		list<int> ans;
		for (int i = n; i >= 1 && t!=s/2; i--) {
			if (t+i<=s/2) {
				t+=i;
				ans.push_back(i);
				u[i-1]=true;
			}
		}
		cout << ans.size() << "\n";
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
		cout << (n-ans.size()) << "\n";
		for (int i = 0; i < n; i++)
			if (u[i]==false)
				cout << (i+1) << " ";
		cout << "\n";
	}
	return 0;
}
