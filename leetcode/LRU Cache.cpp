class LRUCache {
    
    unordered_map<int, list<pair<int,int>>::iterator> data;
    list<pair<int,int>> recent;
    int capacity;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
    	if (data.find(key) == data.end())
    		return -1;
    	
    	auto it = data[key];
    	int val = it->second;
    	recent.erase(it);
    	recent.push_front({key,val});
    	data[key] = recent.begin();
    	return val;
    }
    
    void put(int key, int value) {
    	if (data.find(key) != data.end()) {
    		auto it = data[key];
    		recent.erase(it);
		}
		else if (data.size() == capacity) {
			auto it = recent.rbegin();
			data.erase(it->first);
			recent.pop_back();
		}
		recent.push_front({key,value});
		data[key] = recent.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
