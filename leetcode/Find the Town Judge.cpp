class Solution {
public:
    
    int findJudge(int N, vector<vector<int>>& trust) {
	    unordered_map<int,int> mp;
        unordered_set<int> judge, no_judge;
        
        if (N==1)
            return 1;
        
        for (auto t : trust) {
            mp[t[1]]++;
            if (mp[t[1]] == N-1 && no_judge.find(t[1]) == no_judge.end())
                judge.insert(t[1]);
            judge.erase(t[0]);
            no_judge.insert(t[0]);
        }
        if (judge.size() == 0)
            return -1;
        return *(judge.begin());
    }
};
