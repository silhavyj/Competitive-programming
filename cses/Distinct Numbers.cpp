#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int n,x;
	cin >> n;
	set<int> s;
	while (n--) {
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << "\n";
	return 0;
}
