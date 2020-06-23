#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int n;
	cin >> n;
	multiset<int> s;
	while (n--) {
		int x;
		cin >> x;
		auto it = s.upper_bound(x);
		if (it != s.end())
			s.erase(it);
		s.insert(x);
	}
	cout << s.size() << "\n";
	return 0;
}
