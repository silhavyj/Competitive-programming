class Solution {
public:
    string longestPalindrome(string s) {
	int a = 0, b = 0, m;
	bool is;
	
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < i; j++) {
			if (i-j <= a-b)
				continue;
				
			m = (i-j) / 2;
			is = true;
			for (int k = 0; k <= m; k++)
				if (s[j+k] != s[i-k]) {
					is = false;
					break;
				}
			if (is) {
				a = i;
				b = j;
			}	
		}
	}
	return s.substr(b,a-b+1);
    }
};
