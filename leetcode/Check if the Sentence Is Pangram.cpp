class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> seen(26,0);
        int count=0;
        for (char c : sentence) {
            if (!seen[c-'a']) {
                seen[c-'a']=1;
                if (++count == 26)
                    return true;
            }
        }
        return false;
    }
};
