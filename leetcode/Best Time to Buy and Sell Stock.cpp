class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 0;
        int res = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[min])
                min = i;
            if (prices[i] - prices[min] > 0)
                res = max(res, prices[i] - prices[min]);
        }
        return res;
    }
};
