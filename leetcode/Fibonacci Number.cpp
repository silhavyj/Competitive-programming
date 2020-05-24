class Solution {
public:
    int fib(int N) {
        if (!N) return 0;
        if (N <= 2)
            return 1;
        
        int a=1,b=1,c;
        
        for (int i = 0; i < N-2; i++) {
            c = a + b;
            b = a;
            a = c;
        }
        return c;
    }
};
