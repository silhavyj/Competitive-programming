    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
    	ios::sync_with_stdio(0);
    	cin.tie(0);
    	
    	bool hard=false;
    	int n, op;
    	cin >> n;
    	while (n--) {
    		cin >> op;
    		hard |= op;
    	}
    	cout << (!hard ? "EASY" : "HARD") << "\n";
    	return 0;
    }
