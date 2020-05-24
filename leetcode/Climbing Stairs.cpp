class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1, c;
        
        if (n <= 2)
            return n;
        
        for (int i = 2; i < n+1; i++) {
            c = a + b;
            b = a;
            a = c;
        }
        return c;
    }
};
