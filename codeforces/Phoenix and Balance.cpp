#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, x, y, p;
	cin >> t;
	while (t--) {
		cin >> n;
		x = 1 << n;
		y = 1 << n-1;
		p = (n-2)/2;
		
		for (int i = 1; i <= p; i++)
			x += 1 << i;
		for (int i = p+1; i <= 2*p; i++)
			y += 1 << i;
		
		cout << (x-y) << "\n";
	}
	return 0;
}
