#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string dna;
	cin >> dna;
	int s=0,e=0,ans=1;
	for (int i = 1; i < dna.length(); i++) {
		if (dna[i]==dna[i-1])
			e++;
		else s=e=i;
		ans = max(ans,e-s+1);
	}
	cout << ans << "\n";
	return 0;
}
