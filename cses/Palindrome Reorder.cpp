#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	string str;
	cin >> str;
	unordered_map<char,int> mp;
	for (char c : str)
		++mp[c];
	bool is_odd=0;
	char odd;
	for (auto p : mp) {
		if (p.second & 1) {
			if (is_odd) {
				cout << "NO SOLUTION\n";
				return 0;
			}
			is_odd=1;
			odd=p.first;
		}
	}
	string t="";
	for (auto p : mp) {
		if (p.second & 1)
			continue;
		else for (int i = 0; i < p.second/2; i++)
			t+=p.first;
	}
	cout << t;
	reverse(t.begin(),t.end());
	if (is_odd) {
		for (int i = 0; i < mp[odd]; i++)
			cout << odd;
	}
	cout << t << "\n";
	return 0;
}
