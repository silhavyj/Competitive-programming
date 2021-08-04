class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> forbitten;
        for (string d : deadends)
            forbitten.insert(d);
        
        unordered_set<string> seen;
        queue<pair<string,int>> que;
        
        string start = "0000";
        if (forbitten.count(start) || forbitten.count(target))
            return -1;
        
        que.push({start, 0});
        
        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            if (t.first == target) 
                return t.second;
            
            for (int i = 0; i < 4; i++) {
                string cp = t.first;
                if (cp[i]=='0')
                    cp[i]='9';
                else
                    cp[i]--;
                if (!seen.count(cp) && !forbitten.count(cp)) {
                    que.push({cp, t.second + 1});
                    seen.insert(cp);
                }
                cp = t.first;
                if (cp[i]=='9')
                    cp[i]='0';
                else
                    cp[i]++;
                if (!seen.count(cp) && !forbitten.count(cp)) {
                    que.push({cp, t.second + 1});
                    seen.insert(cp);
                }
            }
        }
        return -1;
    }
};
