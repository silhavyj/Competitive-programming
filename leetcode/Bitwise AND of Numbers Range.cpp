class Solution {
public:
    int solve(int m, int n) {
		int p = 30;
		int mask = 1 << p;
		int ans = 0;
		
		while (mask) {
			int a = (n & mask) >> p;
			int b = (m & mask) >> p;
			
			if (a ^ b)
				return 0;
			
			if (a && b) {
				int val = pow(2,p);
				return val + solve(m-val, n-val);
			}
			
			p--;
			mask >>= 1;
		}
		return 0;
	}

    int rangeBitwiseAnd(int m, int n) {
    	return solve(m,n);
    }
};
