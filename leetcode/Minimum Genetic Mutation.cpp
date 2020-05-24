class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dic;
        unordered_map<string, int> step;
        unordered_set<string> visited;
        vector<char> type = {'A','C','G','T'};
        
        for (auto b : bank)
            dic.insert(b);
        
        queue<string> que;
        que.push(start);
        step[start] = 0;
        visited.insert(start);
        
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            
            if (top == end)
                return step[top];
            
            for (int i = 0; i < top.length(); i++) {
                string next = top;
                for (auto t : type) {
                    next[i] = t;
                    if (dic.find(next) == dic.end() ||
                        visited.find(next) != visited.end())
                        continue;
                    
                    que.push(next);
                    step[next] = step[top] + 1;
                    visited.insert(next);
                }
            }
        }
        return -1;
    }
};
