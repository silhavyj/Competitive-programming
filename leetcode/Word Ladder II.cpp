class Solution {
    unordered_map<string, int> dic;
    unordered_map<int,string> dic2;
    vector<vector<string>> ans;
    unordered_set<int> seen;
    int minLen = INT_MAX;

    void dfs(string curr, string endWord, vector<string> &path, vector<vector<int>> &adj) {
       /* for (string word : path)
            cout << word << " ";
        cout << "\n"; */
        
        if (path.size() > 1+minLen)
            return;
        if (curr == endWord) {
            ans.push_back(path);
            return;
        }
        int id = dic[curr];
        seen.insert(id);
        for (int n : adj[id])
            if (!seen.count(n)) {
                path.push_back(dic2[n]);
                dfs(dic2[n], endWord, path, adj);
                path.pop_back();
            }
        seen.erase(id);
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (string word : wordList) {
            dic[word] = id;
            dic2[id] = word;
            id++;
        }

        if (!dic.count(endWord))
            return {};

        if (!dic.count(beginWord)) {
            dic[beginWord] = id;
            dic2[id] = beginWord;
            id++;
        }

        seen.insert(dic[beginWord]);
        vector<int> depth(dic.size(), INT_MAX);
        depth[dic[beginWord]] = 1;
        vector<vector<int>> adj(dic.size());
        queue<string> que;
        que.push(beginWord);

        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            if (t == endWord) {
                minLen = depth[dic[t]];
            } else if (minLen != INT_MAX && depth[dic[t]] > minLen) {
                break;
            }
            string cp = t;
            for (int i = 0; i < t.length(); i++) {
                char tmp = t[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    t[i] = c;
                    if (dic.count(t)) {
                        if (depth[dic[t]] > depth[dic[cp]]) {
                            adj[dic[cp]].push_back(dic[t]);
                            //adj[dic[t]].push_back(dic[cp]);
                        }
                        if (!seen.count(dic[t])) {
                            seen.insert(dic[t]);
                            depth[dic[t]] = depth[dic[cp]] + 1;
                            que.push(t);
                        }
                    }
                }
                t[i] = tmp;
            }
        }
        if (minLen == INT_MAX)
            return {};
    
        //cout << minLen << "\n";
        
        seen.clear();    
        vector<string> path;
        path.push_back(beginWord);
        dfs(beginWord, endWord, path, adj);
        return ans;
    }
};
