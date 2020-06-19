#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> ans;
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	do {
		ans.push_back(s);	
	} while (next_permutation(s.begin(),s.end()));
	cout << ans.size() << "\n";
	for (string a : ans)
		cout << a << "\n";
	return 0;
}
