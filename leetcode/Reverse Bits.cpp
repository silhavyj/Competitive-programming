class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 2147483648;
        uint32_t y = 1;
        uint32_t res = 0;
        
        for (int i = 0; i < 32; i++) {
            if (((n & y) >> i) == 1)
                res |= x;
            
            x >>= 1;
            y <<= 1;
        }
        return res;
    }
};
