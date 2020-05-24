class Solution {
public:
        
    bool checkValidString(string s) {
        int maxOpen = 0;
        int minOpen = 0;
        
        for (char c : s) {
            if (c == '(') minOpen++;
            else minOpen--;
            if (c != ')') maxOpen++;
            else maxOpen--;
            if (maxOpen < 0)
                break;
            
            if (minOpen < 0)
                minOpen = 0;
        }
        return minOpen == 0;
    }
};
