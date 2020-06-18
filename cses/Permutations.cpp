#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	if (n==1)
		cout << "1\n";
	else if (n <= 3)
		cout << "NO SOLUTION\n";
	else {
		if (n & 1) {
			for (int i=n-1, j=n/2; i>=n/2 && j>=1; --i, --j) {
				cout << i << " " << j << " ";
				if (j==n/2)
					cout << n << " ";
			}
		}
		else {
			for (int i=n, j=n/2; i>=n/2 && j>=1; --i, --j)
				cout << j << " " << i << " ";
		}
	}
	return 0;
}
