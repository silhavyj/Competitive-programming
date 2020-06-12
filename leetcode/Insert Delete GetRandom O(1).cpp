class RandomizedSet {
    
    unordered_map<int, int> mp;
    vector<int> vals;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((int)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val) != 0)
            return false;
        mp[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.count(val)==0)
            return false;
        int i = mp[val];
        mp.erase(val);
        if (i==vals.size()-1) {
            vals.pop_back();
            return true;
        }
        vals[i] = vals[vals.size()-1];
        vals.pop_back();
        mp[vals[i]] = i;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand()%vals.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
