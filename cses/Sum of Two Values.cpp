#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	cin >> n >> x;
	int a[n];
	map<int,int> mp;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (mp.find(a[i])!=mp.end()) {
			cout << mp[a[i]] << " " << (i+1) << "\n";
			return 0;
		}
		mp[x-a[i]]=i+1;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
