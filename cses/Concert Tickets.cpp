#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int n, m, x;
	multiset<int, greater<int>> t;
	cin >> n >> m;
	while (n--) {
		cin >> x;
		t.insert(x);
	} 
	while (m--) {
		cin >> x;
		auto it = t.lower_bound(x);
		if (it == t.end())
			cout << "-1\n";
		else {
			cout << *it << "\n";
			t.erase(it);
		}
	}
	return 0;
}
