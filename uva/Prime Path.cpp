#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4;
unordered_set<int> primes;
int num[4];

void sieve() {
	bool ok[N];
	memset(ok, 1, sizeof(ok));
	int t = (int)sqrt(N);
	for (int i=2; i < t; i++)
		if (ok[i])
			for (int j=2*i; j < N; j+=i)
				ok[j]=0;
	for (int i = 0; i < N; i++)
		if (ok[i])
			primes.insert(i);
}

int get_num() {
	int res = 0;
	int m = 1;
	for (int i = 3; i >= 0; i--) {
		res += num[i] * m;
		m *= 10;
	}
	return res;
}

void fill_num(int n) {
	int m = 1000;
	for (int i = 0; i < 4; i++) {
		num[i] = n / m;
		n %= m;
		m /= 10;
	}
}

void solve() {
	int a, b, n, tmp;
	unordered_map<int,int> step;
	queue<int> que;
	cin >> a >> b;
	que.push(a);
	step[a]=0;
	
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		if (t==b)
			break;
		fill_num(t);
		for (int i = 0; i < 4; i++) {
			tmp=num[i];
			for (int j = 0; j <= 9; j++) {
				num[i]=j;
				n = get_num();
				if (n >= 1000 && primes.find(n)!=primes.end() && step.find(n)==step.end()) {
					step[n] = step[t]+1;
					que.push(n);
				}
			}
			num[i]=tmp;
		}
	}
	if (step.find(b) == step.end())
		cout << "Impossible\n";
	else cout << step[b] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	sieve();	
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
