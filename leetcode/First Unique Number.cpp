class FirstUnique {

list<int> order;
unordered_map<int, list<int>::iterator> mp;
unordered_set<int> used;    
    
public:
    FirstUnique(vector<int>& nums) {
        for (int n : nums)
            add(n);
    }
    
    int showFirstUnique() {
        return order.size() == 0 ? -1 : *(order.begin());
        return -1;
    }
    
    void add(int value) {
        if (used.find(value) == used.end()) {
            order.push_back(value);
            mp[value] = --order.end();
            used.insert(value);
        }
        else {
            if (mp.find(value) != mp.end()) {
                order.erase(mp[value]);
                mp.erase(value);
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
