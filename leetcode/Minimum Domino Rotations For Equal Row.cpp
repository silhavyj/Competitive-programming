class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_set<int> top, bottom;
        for (int i = 0; i < tops.size(); i++) {
            top.insert(tops[i]);
            bottom.insert(bottoms[i]);
        }
        if (top.size()==1 || bottom.size()==1)
            return 0;
            
        bool possible;
        int ans = INT_MAX;
        int move;
        
        for (int target : top) {
            possible = true;
            move = 0;
            for (int i = 0; i < tops.size() && possible; i++) {
                if (tops[i] != target) {
                    if (bottoms[i] == target)
                        move++;
                    else
                        possible = false;
                }
            }
            if (possible)
                ans = min(ans, move);
        }
        for (int target : bottom) {
            possible = true;
            move = 0;
            for (int i = 0; i < bottoms.size() && possible; i++) {
                if (bottoms[i] != target) {
                    if (tops[i] == target)
                        move++;
                    else
                        possible = false;
                }
            }
            if (possible)
                ans = min(ans, move);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
