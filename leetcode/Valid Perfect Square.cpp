class Solution {
public:
    bool isPerfectSquare(int num) {       
   int lb = 1;
   int rb = num;
   
   while (lb <= rb) {
     int m = lb+(rb-lb)/2;
     long long val = (long long)m*m;
     if (val > INT_MAX) {
        rb=m-1;
        continue;
     }
     if (val == num)
        return true;
     if (val < num)
        lb=m+1;
     else rb=m-1;
   }
   return false;
}
};
