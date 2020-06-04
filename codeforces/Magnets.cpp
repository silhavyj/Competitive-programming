#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans=1;
	char a,b;
	cin >> n;
	while (n--) {
		cin >> a;
		ans += a==b;
		cin >> b;
	}
	cout << ans << "\n";
	return 0;
}
