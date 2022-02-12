class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for (auto &log : logs) {
            if (log == "../")
                depth = max(0, depth - 1);
            else if (log[0]!='.')
                depth++;
        }
        return depth;
    }
};
