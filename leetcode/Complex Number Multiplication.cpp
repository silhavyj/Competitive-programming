class Solution {
    pair<int,int> getNums(string &num) {
        int plusPos = 0;
        while (num[plusPos] != '+')
            plusPos++;
        int x = atoi(num.substr(0, plusPos).c_str());
        int y = atoi(num.substr(plusPos+1, num.length()-plusPos).c_str());
        return {x,y};
    }
public:
    string complexNumberMultiply(string num1, string num2) {
        // (x + yi)(u + vi) = (xu - yv) + (xv + yu)i
        pair<int,int> n1 = getNums(num1);
        pair<int,int> n2 = getNums(num2);
        
        int r1 = (n1.first * n2.first) - (n1.second * n2.second);
        int r2 = (n1.first * n2.second) + (n1.second * n2.first);
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};
