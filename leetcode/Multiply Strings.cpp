class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<string> rows;
        int maxRow = 0;
        int c;
        for (int i = num1.length()-1; i >= 0; i--)  {
            string row = "";
            for (int j = 0; j < num1.length()-1-i; j++)
                row += "0";
            c = 0;        
            for (int j = num2.length()-1; j >= 0; j--) {
                int x = (num1[i]-'0')*(num2[j]-'0')+c;
                row = to_string(x % 10) + row;
                c = x / 10;
            }
            if (c != 0)
                row = to_string(c) + row;
            rows.push_back(row);
            if (row.length() > maxRow)
                maxRow = row.length();
        }
        for (string &row : rows) {
            string padding = "";
            for (int i = row.length(); i < maxRow; i++)
                padding += "0";
            row = padding + row;
            //cout << row << "\n";
        }
        string ans = "";
        c = 0;
        for (int j = maxRow-1; j >= 0; j--) {
            int sum=0;
            for (int i = 0; i < rows.size(); i++)
                sum += (rows[i][j]-'0');
            sum += c;
            ans = to_string(sum % 10) + ans;
            c = sum / 10;
        }
        if (c != 0)
            ans = to_string(c) + ans;
        return ans;
    }
};
