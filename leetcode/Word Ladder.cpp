class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic;
    unordered_map<string, int> depth;
    unordered_set<string> visited;
    
    for (auto w : wordList)
    	dic.insert(w);
    	
    queue<string> que;
    depth[beginWord] = 1;
    visited.insert(beginWord);
    que.push(beginWord);
    
    while (!que.empty()) {
    	auto top = que.front();
    	que.pop();
    	
    	if (top == endWord)
    		return depth[top];
    	
    	for (int i = 0; i < top.length(); i++) {
    		string next = top;
    		for (char l = 'a'; l <= 'z'; l++) {
    			next[i] = l;
    			if (dic.find(next) == dic.end() ||
					visited.find(next) != visited.end())
					continue;
				
				visited.insert(next);
				que.push(next);
				depth[next] = depth[top] + 1;
			}
		}
	}
	return 0;
    }
};
