#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,x;
	int a,b;
	cin >> n;
	while (n!=0) {
		priority_queue<int, vector<int>, greater<int>> que;
		int ans=0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			que.push(x);
		}
		while (1) {
			a = que.top(), que.pop();
			b = que.top(), que.pop();
			ans += a+b;
			if (que.empty())
				break;
 			que.push(a+b);
		}
		cout << ans << "\n";
		cin >> n;
	}
	return 0;
}
