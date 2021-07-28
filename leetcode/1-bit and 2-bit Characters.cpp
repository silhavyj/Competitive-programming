class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size(); ) {
            if (bits[i]==1)
                i+=2;
            else {
                if (i==bits.size()-1)
                    return true;
                i++;
            }
        }
        return false;
    }
};
