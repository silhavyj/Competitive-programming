class Solution {
public:
    string toHex(int num) {
        char str[9];
        sprintf(str, "%x", num);
        return string(str);
    }
};
