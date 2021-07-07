class Solution {
public:
    int secondHighest(string s) {
        set<int, std::greater<int>> nums;
        for (char c : s)
            if (c >= '0' && c <= '9')
                nums.insert(c-'0');
        if (nums.size() < 2)
            return -1;
        return *(++nums.begin());
    }
};
