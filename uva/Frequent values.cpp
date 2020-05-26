#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,q,a,b;
int parts;
int s[100005],len[100005];
int tree[1000005];

void create(int p, int l, int r) {
	if (l+1 == r) {
		tree[p] = s[l+1]-s[l];
		return;
	}
	int m = l+(r-l)/2;
	create(2*p, l, m);
	create(2*p+1, m, r);
	tree[p] = max(tree[2*p],tree[2*p+1]);
}

int query(int p, int l, int r, int ql, int qr) {
	if (l >= qr || r <= ql)
		return 0;
	if (l >= ql && r <= qr)
		return tree[p];
	int m = l+(r-l)/2;
	return max(query(2*p,l,m,ql,qr), query(2*p+1,m,r,ql,qr));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);			

	cin >> n;
	while (n) {	
		cin >> q;
		parts = 0;
		int prev, val;
		len[1]=0;
		s[0]=1;
		cin >> prev;
		for (int i = 2; i <= n; i++) {
			cin >> val;
			if (val != prev) {
				parts++;
				s[parts] = i;
				prev = val;
			}
			len[i] = parts;
		}
		parts++;
		s[parts] = n+1;
		
		create(1,0,parts);
		while (q--) {
			cin >> a >> b;
			int first = len[a];
			int last = len[b];
			int ans = min(s[first+1],b+1) - max(s[first],a);
			if (first != last) {
				ans = max(ans, min(s[last+1],b+1)-s[last]);
				ans = max(ans, query(1,0,parts,first+1,last));
			}
			cout << ans << "\n";
		}
		cin >> n;
	}
	return 0;
}
