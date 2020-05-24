#define ll long long 
class Solution {

public:
vector<int> ans;

bool solve(ll x, ll y, int p, int n, string &s) {
	while (p != n) {
		ll z = x + y;
        if (z >= INT_MAX)
            return false;
		int len = to_string(z).length();
		if (p + len > n)
			return false;
		ll res = stoll(s.substr(p,len));		
		if (res != z)
			return false;
		ans.push_back(res);
		x = y;
		y = z;
		p += len; 
	}
	return true;
}

vector<int> splitIntoFibonacci(string S) {
	int n=S.length();
	for (int i = 1; i < n-1; i++) {
		ll x = stoll(S.substr(0,i));
		if (x >= INT_MAX)
			break;
		for (int j = 1; i+j < n-1; j++) {
			ll y = stoll(S.substr(i,j));
			if (y >= INT_MAX)
				break;
				
			ans.clear();
			ans.push_back(x);
			ans.push_back(y);
			if (solve(x,y,i+j,n,S))
				return ans;
		}   
	}
	ans.clear();
	return ans;     
}
};
