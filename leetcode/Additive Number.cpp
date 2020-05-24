class Solution {
public:
    
typedef long long ll;
bool ans = false;

void solve(string num, int p, ll a, ll b) {
	while (p < num.length()) {
		ll c = a + b;
        
		int len = to_string(c).length();
		ll res = stoll(num.substr(p,len));		
        
		if (res != c)
			return;
		
		a = b;
		b = c;
		p+=len;
	}
	ans = true; 
}

bool isAdditiveNumber(string num) {
	 if (num.length() < 3)
        return false;
	ll a,b;
	string t;
	for (int i = 1; i < num.length(); i++) {
		t = num.substr(0,i);
		if (t[0] == '0' && i > 1)
			continue;
		a = stoll(t);
		for (int j = 1; j < num.length(); j++) {
			t = num.substr(i,j);
			if (t[0] == '0' && j > 1)
				continue;
			b = stoll(t);
			if (j+i < num.length())
				solve(num, j+i, a, b);
			if (ans == true)
				return true;
		}
	}
	return false;
}
};