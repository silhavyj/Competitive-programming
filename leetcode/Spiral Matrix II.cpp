/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int state = 0;
        int i=0, j=0;
        
        if (matrix.size() == 0)
            return ans;
        
        int p = 0, s = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        while (true) {
            ans.push_back(matrix[i][j]);
            s++;
            if (s == n*m)
                break;
            switch (state) {
                case 0:
                    if (j+1 == m-p) {
                        state = 1;
                        i++;
                    }
                    else j++;
                    break;
                
                case 1:
                    if (i+1 == n-p) {
                        state = 2;
                        j--;
                    }
                    else i++;
                    break;
                    
                case 2:
                    if (j == p) {
                        state = 3;
                        i--;
                    }
                    else j--;
                    break;
                    
                case 3:
                    if (i-1 == p) {
                        p++;
                        j++;
                        state = 0;
                    }
                    else i--;
                    break;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        int m[n][n];
        int s = 0;
        int p = 0;
        int i=0, j=0;
        int state = 0;
        
        while (true) {
            m[i][j] = ++s;
            if (s == n*n) 
                break;
            
             switch (state) {
                case 0:
                    if (j+1 == n-p) {
                        state = 1;
                        i++;
                    }
                    else j++;
                    break;
                
                case 1:
                    if (i+1 == n-p) {
                        state = 2;
                        j--;
                    }
                    else i++;
                    break;
                    
                case 2:
                    if (j == p) {
                        state = 3;
                        i--;
                    }
                    else j--;
                    break;
                    
                case 3:
                    if (i-1 == p) {
                        p++;
                        j++;
                        state = 0;
                    }
                    else i--;
                    break;
            }
        }
        for (i = 0; i < n; i++) {
            vector<int> line;
            for (j = 0; j < n; j++)
                line.push_back(m[i][j]);
            ans.push_back(line);
        }
        return ans;
    }
};
