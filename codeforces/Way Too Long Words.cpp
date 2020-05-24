#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,l;
	string s;
	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin,s);
		l = s.length();
		if (l<=10)
			cout << s << "\n";
		else cout << s[0]+to_string(l-2)+s[l-1] << "\n"; 	
	}
	return 0;
}
