class MyCircularQueue {
public:
    
    int *data;
    int size;
    int L, R;
    int elm=0;
    
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        data = new int[k];
        L = 0;
        R = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        data[R] = value;
        if (++R == size)
            R = 0;
        elm++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        if (++L == size)
            L = 0;
        elm--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
       return isEmpty() ? -1 : data[L];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        int tmp = R-1;
        if (tmp == -1)
            tmp = size-1;
        return isEmpty() ? -1 : data[tmp];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return elm==0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return elm==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
