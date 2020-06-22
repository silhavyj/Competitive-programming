#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	vector<pair<int,int>> t;
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		t.push_back({a,1});
		t.push_back({b,-1});
	}
	sort(t.begin(),t.end());
	int x=0, ans=0;
	for (auto p : t) {
		x+=p.second;
		ans = max(ans,x);
	}
	cout << ans << "\n";
	return 0;
}
