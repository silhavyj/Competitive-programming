class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](auto &x, auto &y) {
            return abs(x) < abs(y);
        });
        unordered_map<int,int> count;
        for (int a : arr)
            count[a]++;
        
        for (int a : arr) {
            if (count[a]==0)
                continue;
            if (count[2*a]==0)
                return false;
            count[2*a]--;
            count[a]--;
        }
        return true;
    }
};
