class MyHashMap {
private:
    const int MAX_SIZE = 100;
    const int INIT_SIZE = 2;

    struct Node {
        int key;
        int val;
        Node *next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
        }
    };

    Node **data = NULL;
    int *sizes = NULL;
    int size;

private:
    inline int hash(int x) {
        int h = 31;
        return 17 * h + x;
    }

    void put(Node **data, int *sizes, int size, int key, int val) {
        int h = hash(key) % size;
        Node *curr = data[h];
        while (curr != NULL) {
            if (curr->key == key) {
                curr->val = val;
                return;
            }
            curr = curr->next;
        }
        Node *node = new Node(key, val);
        node->next = data[h];
        data[h] = node;
        sizes[h]++;
    }

    void initData(Node **data, int *sizes, int size) {
        for (int i = 0; i < size; i++) {
            data[i] = NULL;
            sizes[i] = 0;
        }
    }

    void resizeUp() {
        Node **data_new = new Node*[2*size];
        int *sizes_new = new int[2*size];
        initData(data_new, sizes_new, 2*size);

        for (int i = 0; i < size; i++) {
            Node *curr = data[i];
            Node *prev;
            while (curr != NULL) {
                put(data_new, sizes_new, 2*size, curr->key, curr->val);
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }
        delete[] data;
        delete[] sizes;
        size *= 2;
        data = data_new;
        sizes = sizes_new;
    }

    void resizeDown() {
        Node **data_new = new Node*[size/2];
        int *sizes_new = new int[size/2];
        initData(data_new, sizes_new, size/2);

        for (int i = 0; i < size; i++) {
            Node *curr = data[i];
            Node *prev;
            while (curr != NULL) {
                put(data_new, sizes_new, size/2, curr->key, curr->val);
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }
        delete[] data;
        delete[] sizes;
        size /= 2;
        data = data_new;
        sizes = sizes_new;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        data = new Node*[INIT_SIZE];
        sizes = new int[INIT_SIZE];
        initData(data, sizes, INIT_SIZE);
        size = INIT_SIZE;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key) % size;
        if (sizes[h] == MAX_SIZE)
            resizeUp();
        put(data, sizes, size, key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key) % size;
        Node *curr = data[h];
        while (curr != NULL) {
            if (curr->key == key)
                return curr->val;
            curr = curr->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key) % size;
        Node *curr = data[h];
        Node *prev = NULL;
        while (curr != NULL) {
            if (curr->key == key) {
                if (prev==NULL)
                    data[h]=data[h]->next;
                else
                    prev->next = curr->next;
                delete curr;
                sizes[h]--;
                int zeros = 0;
                for (int i = 0; i < size; i++)
                    zeros += sizes[i] == 0;
                if (zeros > size / 2 && (size / 2 >= INIT_SIZE))
                    resizeDown();
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
