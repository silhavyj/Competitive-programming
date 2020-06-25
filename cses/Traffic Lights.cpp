#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int x,n,p;
	set<int> s;
	map<int,int> mp;
	cin >> x >> n;
	s.insert(0);
	s.insert(x);
	mp[x]=1;
	for (int i=0; i<n; ++i) {
		cin >> p;
		auto it=s.lower_bound(p);
		int r=*it;
		--it;
		int l=*it;
		--mp[r-l];
		if (!mp[r-l])
			mp.erase(r-l);
		s.insert(p);
		++mp[r-p];
		++mp[p-l];
		cout << (--mp.end())->first << "\n";
	}
	return 0;
}
