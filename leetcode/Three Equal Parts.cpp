class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum=0;
        for (int x : arr)
            sum += x;
        if (sum % 3 != 0)
            return {-1,-1};
        int t = sum/3;
        if (t==0)
            return {0,(int)arr.size()-1};
        sum = 0;
        int i1, j1;
        int i2, j2;
        int i3, j3;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i]==1) {
                sum++;
                if (sum==1) i1 = i;
                if (sum==t) j1 = i;
                if (sum==t+1) i2 = i;
                if (sum==2*t) j2 = i;
                if (sum==2*t+1) i3 = i;
                if (sum==3*t) j3 = i;
            }
        
        /*cout << i1 << " " << j1 << "\n";
        cout << i2 << " " << j2 << "\n";
        cout << i3 << " " << j3 << "\n";*/
        
        for (int i = 0; i <= (j1-i1); i++)
            if (arr[i1+i] != arr[i2+i] || arr[i2+i] != arr[i3+i])
                return {-1,-1};
        
        int numOfZeroX = i2-j1-1;
        int numOfZeroY = i3-j2-1;
        int numOfZeroZ = arr.size()-j3-1;
        
        if (numOfZeroX < numOfZeroZ || numOfZeroY < numOfZeroZ)
            return {-1,-1};
        
        j1 += numOfZeroZ;
        j2 += numOfZeroZ;
        return {j1, j2+1};
    }
};
