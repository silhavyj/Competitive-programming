class Solution {
public:
    #define min(x,y) ((x) < (y) ? (x) : (y))
    int distributeCandies(vector<int>& candyType) {
        set<int> type;
        for (int candy : candyType)
            type.insert(candy);
        int n = candyType.size() / 2;
        return min(n,type.size());
    }
};
