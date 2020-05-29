/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1, r=n;
        while (l <= r) {
            int m = l+(r-l)/2;
            int a = guess(m);
            if (a==0)
                return m;
            else if(a==-1)
                r=m;
            else l=m+1;
        }
        return -1;
    }
};
