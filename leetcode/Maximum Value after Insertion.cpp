class Solution {
public:
    string maxValue(string n, int x) {
        if (n[0]=='-') {
            int i = 1;
            while (i < n.length() && (n[i]-'0') <= x)
                i++;
            return n.substr(0,i) + to_string(x) + n.substr(i,n.length());
        }
        int i = 0;
        while (i < n.length() && (n[i]-'0') >= x)
            i++;
       return n.substr(0,i) + to_string(x) + n.substr(i,n.length());
    }
};
