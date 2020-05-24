class Solution {
public:
    
    unordered_map<char,int> dic;
    
    int compare(string &s1, string &s2) {
        int p1=0, p2=0;
        while (p1 < s1.length() && p2 < s2.length()) {
            if (dic[s1[p1]] < dic[s2[p2]])
                return -1;
            else if (dic[s1[p1]] > dic[s2[p2]])
                return 1;
            p1++, p2++;
        }
        if (s1.length() == s2.length())
            return 0;
        if (p1 == s1.length())
            return -1;
        return 1;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.length(); i++)
            dic[order[i]] = i;
        for (int i = 0; i < words.size()-1; i++)
            if (compare(words[i],words[i+1]) == 1)
                return false;
        return true;
    }
};
