#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	while (n!=0) {
		int x, ans=0, sum=0;
		bool all_neg = true;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x > 0)
				all_neg = false;
			sum += x;
			ans = max(ans, sum);
			sum = max(sum, 0);
		}
		if (all_neg)
			cout << "Losing streak.\n";
		else cout << "The maximum winning streak is " << ans << ".\n";
		cin >> n;
	}	
	return 0;
}
