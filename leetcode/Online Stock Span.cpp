class StockSpanner {
    
    stack<pair<int,int>> st;
    int n=1;
    
public:
    StockSpanner() {    
    }
    
    int next(int price) {
        int ans;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        if (st.empty())
            ans = n;
        else ans = n-st.top().second;
        st.push({price, n++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
