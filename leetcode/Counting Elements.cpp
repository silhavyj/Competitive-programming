class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> count;
        int res = 0;
        
        for (auto x : arr)
            if (count.find(x-1) == count.end())
                count.insert(x-1);
        
        for (auto x : arr)
            if (count.find(x) != count.end())
                res++;
        return res;
    }
};
