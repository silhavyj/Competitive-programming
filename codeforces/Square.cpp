    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
     
    	int t;
    	int a1, b1, a2, b2;
    	cin >> t;
    	while (t--) {
    		cin >> a1 >> b1 >> a2 >> b2;
    		if ((b1==b2 && a1+a2==b1) || 
    			(b1==a2 && b2+a1==b1) ||
    			(a1==a2 && b1+b2==a1) ||
    			(a1==b2 && b1+a2==a1))
    			cout << "Yes\n";
    		else cout << "No\n";
    	}
    	return 0;
    }
