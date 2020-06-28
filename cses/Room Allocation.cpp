#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2e5;
array<int,3> a[maxN];
int n, ans[maxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i][1] >> a[i][0];
		a[i][2]=i;
	}
	sort(a,a+n);
	set<array<int,2>> s;
	for (int i=0; i<n; ++i) {
		auto it=s.lower_bound({a[i][1]});
		if (it!=s.begin()) {
			--it;
			ans[a[i][2]]=(*it)[1];
			s.erase(it);
		}
		else
			ans[a[i][2]]=s.size();
		s.insert({a[i][0],ans[a[i][2]]});
	}
	cout << s.size() << "\n";
	for (int i=0; i<n; ++i)
		cout << ans[i]+1 << " ";
	cout << "\n";
	return 0;
}
