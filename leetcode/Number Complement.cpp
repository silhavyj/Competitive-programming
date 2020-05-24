class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int p = 30;
        while (!((num & (1<<p)) >> p))
            p--;
        
        for (int i = p; i >= 0; i--)
            ans |= (!(((num & (1<<i)) >> i)) << i);
        return ans;
    }
};
