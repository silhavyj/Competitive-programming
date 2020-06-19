class Solution {
public:
    
    typedef long long ll;
    const int MOD = 1e9+7;
    vector<ll> p;
        
    string solve(string& S, int k) {
		if (k==0)
			return "";
		unordered_map<ll,vector<int>> mp;
		ll h=0;
		for (int i=k-1; i>=0; i--) 
            h=(h % MOD +(p[k-1-i]*(S[i]-'a'+1)) % MOD) % MOD;
		for (int i=0; ; i++) {
			if(mp.find(h)!=mp.end()) {
				for (int x : mp[h]) {
					string ans = S.substr(x,k); 
					if (ans==S.substr(i,k))
                        return ans;
				}
                mp[h].push_back(i);
			}
			else mp[h]=vector<int>(1,i);
			if (i+k==S.length())
				break;
            h=(h % MOD - ((p[k-1]*(S[i]-'a'+1)) % MOD) + MOD) % MOD;
            h=(h % MOD * 26 % MOD) % MOD;
            h=(h % MOD + ((p[0]*(S[k+i]-'a'+1)) % MOD)) % MOD;
		}
        return "";
	}
	
    string longestDupSubstring(string S) {
		p.resize(S.size()+1);
        p[0]=1;
        for(int i=1; i <= S.size(); i++)
            p[i]=(26*p[i-1])%MOD;
        int l=0, r=S.length();
        string ans = "";
        while (l <= r) {
            int m = l+(r-l)/2;
            string s = solve(S,m);
            if (s != "") {
                if (s.length() > ans.length())
                    ans = s;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};
