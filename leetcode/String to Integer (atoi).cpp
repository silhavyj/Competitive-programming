class Solution {
public:
    int pow(int p) {
	long long res = 1;
	for (int i = 0; i < p; i++) {
		res *= 10;
		if (res >= INT_MAX)
			return -1;
	}
	return res;
}
    
    int multi(int a, int b) {
        if (a == 0 || b == 0)
            return 0;
	long long res = a;
	for (int i = 1; i < b; i++) {
		if (res + a >= INT_MAX)
			return -1;
		res += a;	
	}
	return res;
}

    int myAtoi(string str) {
int i = 0;
	int n = str.length();
	bool neg = false;
	list<char> nums;
	int ans = 0;
	long long v;
	int p, pp;
	
	while (i < n) {
		if (str[i] != '-' && str[i] != '+' && str[i] != ' ' && 
		    !(str[i] >= '0' && str[i] <= '9'))
		    return 0;
		    
		if (str[i] == '-' || str[i] == '+') {
			if (i == n-1)
				return 0;
			if (!(str[i+1] >= '0' && str[i+1] <= '9'))
				return 0;
			neg = str[i] == '-';
			i++;
			break;
		}
		if (str[i] >= '0' && str[i] <= '9')
			break;
		i++;
	}
	bool first = true;
	while (i < n) {
		if (first) {
			if (str[i] != '0') {
				if (str[i] > '0' && str[i] <= '9') {
					nums.push_back(str[i]);
					first = false;
				}
				else break;
			}
		}
		else {
			if (str[i] >= '0' && str[i] <= '9')
				nums.push_back(str[i]);
			else break;
		}
		i++;	
	}
	p = nums.size() - 1;
	for (char x : nums) {
		pp = pow(p--);
		if (pp == -1)
			return neg ? INT_MIN : INT_MAX;
			
		v = multi(pp, (int)x - 48);
		if (v == -1)
			return neg ? INT_MIN : INT_MAX;
		if (!neg && ans + v >= INT_MAX)
			return INT_MAX;
		if (neg && -(ans + v) <= INT_MIN)
			return INT_MIN;
			
		ans += v;
	}
	if (neg)
		ans *= -1;
	return ans;
    }
};
