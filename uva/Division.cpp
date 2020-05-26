#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool test(int x, unordered_set<int>& m) {
	int k;
	for (int i = 1e4; i; i /= 10) {
		k = x/i;
		if (m.find(k)!=m.end())
			return false;
		m.insert(k);
		x -= k*i;
	}
	return true;
}

bool ok(int a, int b) {
	unordered_set<int> m;
	return test(a,m) && test(b,m);
}

void print(int x) {
	if (x < 1e4)
		cout << "0" << x;
	else cout << x;
}

void solve(int n) {
	int b = 1000;
	bool found = false;
	while (1) {
		int a = n*b;
		if (a >= 1e5)
			break;
		if (ok(a,b)) {
			found = true;
			print(a);
			cout << " / ";
			print(b);
			cout << " = " << n << "\n";
		}
		b++;
	}		
	if (!found)
		cout << "There are no solutions for " << n << ".\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while (n) {
		solve(n);
		cin >> n;
		if (n!=0)
			cout << "\n";
	}
	return 0;
}
