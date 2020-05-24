#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x;
	unordered_map<int,int> mp1,mp2;
	vector<int> pos;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		mp1[x] = i;
	}
	for (auto p : mp1) {
		mp2[p.second] = p.first;
		pos.push_back(p.second);
	}
	sort(pos.begin(), pos.end());
	cout << pos.size() << "\n";
	for (int i = 0; i < pos.size(); i++) {
		cout << mp2[pos[i]];
		if (i != pos.size() - 1)
			cout << " ";
	}
	cout << "\n";
	return 0;
}
