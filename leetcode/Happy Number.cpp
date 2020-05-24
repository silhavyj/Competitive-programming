class Solution {
public:
    int sum(int n) {
        int sum = 0;
        while (n) {
            int d = n % 10;
            n /= 10;
            sum += d*d;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (true) {
            n = sum(n);
            if (n == 1)
                return true;
            if (visited.find(n) != visited.end())
                return false;
            visited.insert(n);
        }
    }
};
