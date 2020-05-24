class CustomStack {
    list<int> data;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (data.size() < maxSize)
            data.push_back(x);
    }
    
    int pop() {
        if (data.size() == 0)
            return -1;
        
        int x = data.back();
        data.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        int i = 0;
        for (int &d : data) {
            if (i == k)
                return;
            d += val;
            i++;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
