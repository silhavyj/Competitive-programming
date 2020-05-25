#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+1;

void solve(int n, int m) {
	bool ok=true, out;
	int a,b,c;
	bitset<N> u;
	
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = a; j < b && ok; j++) {
			if (u[j]==1)
				ok = false;
			else u[j] = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		out = false;
		while (!out && ok) {
			for (int j = a; j < b && ok && !out; j++) {
				if (j >= N)
					out = true;
				else if (u[j]==1)
					ok = false;
				else u[j] = 1;
			}
			a+=c, b+=c;
		}
	}
	cout << (ok ? "NO CONFLICT\n" : "CONFLICT\n");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin >> n >> m;
	while (n || m) {
		solve(n,m);
		cin >> n >> m;
	}
	return 0;
}
