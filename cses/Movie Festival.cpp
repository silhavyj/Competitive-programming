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
		t.push_back({a,b});
	}
	sort(t.begin(),t.end(),[](pair<int,int>& x, pair<int,int>& y) {
		return x.second < y.second;
	});
	int ans=1, end=t[0].second;
	for (int i=1; i<n; ++i) {
		if (t[i].first >= end) {
			end = t[i].second;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
