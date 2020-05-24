class Solution {
public:
    
    int multi(int a, int b) {
	if (a == 0 || b == 0)
		return 0;

        if ((long long)a*b >= INT_MAX)
            return -1;
        return a*b;
}

int power(int a, int b) {
	long long res = a;
	long long m;
	for (int i = 1; i < b; i++) {
		m = multi(res, a);
		if (m == -1)
			return -1;
		res = m;
	}
	return res;
} 
    
    int reverse(int x) {
	if (x == 0)
		return 0;
		
	long long res = 0;
	int p, m, n;
	bool neg = false;
	if (x < 0)
		neg = true;
        
	x = abs(x); 
    if (x < 0)
        return 0;
	
    while (x % 10 == 0)
    	x /= 10;
    
    p = x > 0 ? (int)log10((double)x) : 0;
    if (x < 0)
        return 0;
    while (x != 0) {
    	m = pow(10, p--);
    	if (m == -1)
    		return 0;
    	n = multi(x % 10, m);
    	if (n == -1)
    		return 0;
    	if (res + n >= INT_MAX)
    		return 0;
    	res += n;
    	x /= 10;
	}
    return neg ? -1 * res : res;
    }
};
