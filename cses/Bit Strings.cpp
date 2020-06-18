#include <bits/stdc++.h>
#define ll long long
using namespace std;

int modpow(int x, int n, int m) {
	if (n == 0)
		return 1 % m;
	long long u = modpow(x,n/2,m);
	u = (u*u)%m;
	if (n & 1)
		u = (u*x)%m;
	return u;
}

const int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	cout << modpow(2,n,MOD) << "\n";
	return 0;
}
