    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
     
    	int n, c, w1, w2=-1;
    	int ans = 0;
    	
    	cin >> n >> c;
    	for (int i = 0; i < n; i++) {
    		cin >> w1;
    		ans++;
    		if (w2 != -1 && w1-w2 > c)
    			ans = 1;
    		w2 = w1;
    	}
    	cout << ans << "\n";
    	return 0;
    }
