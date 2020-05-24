class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;
        
        for (int s : stones)
            que.push(s);
        
        while (!que.empty()) {
            int x = que.top();
            que.pop();
            if (que.empty())
                return x;
            int y = que.top();
            que.pop();
            if (x == y)
                continue;
            else que.push(x-y);
        }
        return 0;
    }
};
