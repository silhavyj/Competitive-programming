#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,ans=0;
	string a,b;
	
	cin >> n;
	cin.ignore();
	getline(cin,a);
	getline(cin,b);
	
	for (int i = 0; i < n; i++) {
		int tmp = abs(a[i]-b[i]);
		if (tmp >= 5)
			ans+=9-tmp+1;
		else ans+=tmp;
	}
	cout << ans << "\n";
	return 0;
}
