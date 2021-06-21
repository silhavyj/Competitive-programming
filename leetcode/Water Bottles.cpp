class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {        
        int ans = 0;
        int leftover = 0;
        
        while (numBottles != 0) {
            ans += numBottles;
            leftover += numBottles % numExchange;
            numBottles /= numExchange;
            if (leftover >= numExchange) {
                numBottles++;
                leftover -= numExchange;
            }
        }
        return ans;
    }
};
