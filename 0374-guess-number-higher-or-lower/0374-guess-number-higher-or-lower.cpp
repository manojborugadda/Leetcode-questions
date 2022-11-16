/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// here we are using BINARY SEARCH 
class Solution {  //TC:O(logn)  SC:O(1)
public:
    int guessNumber(int n) {
        long low = 1 ,  high = n; 
        while(low <= high) {
            long mid = (low+high)>>1;
            int result = guess(mid);
            if(result == 0) { // when our PICKED number is equal to NUM
                return mid;
            }else if(result < 0) { // when our PICKED number is less than NUM
                high = mid-1;
            }else{ // when our PICKED number is greater than NUM
                low = mid+1;
            }
        }
        return -1;
    }
};