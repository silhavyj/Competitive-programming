static int x=[](){ios_base::sync_with_stdio(false); cin.tie(NULL); return 0;}();
class MinStack {
public:
    /** initialize your data structure here. */
    list<int> s;
    
    MinStack() {
    }
    
    void push(int x) {
        s.push_back(x);
    }
    
    void pop() {
        s.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        int x = INT_MAX;
        for (int n : s)
            x = min(x, n);
        return x;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
