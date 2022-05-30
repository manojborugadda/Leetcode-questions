///------------FIRST APPROACH--------------------------------------

// class Solution {  // TC:O(a/b) SC:O(1)
// public:
//     int divide(int dividend, int divisor) {
        
//         // dividend = quotient * divisor + remainder
        
        
//         // Calculate sign of divisor i.e.,
//           // sign will be negative only if
//           // either one of them is negative
//           // otherwise it will be positive
//         int sign = ( (dividend < 0)^(divisor < 0) ? -1:1);
        
//         // update both Divisor and Divided positive
//         dividend = abs(dividend);
//         divisor = abs(divisor);
        
//         //finding the quotient
//         int quotient = 0;  //intialising the Quotient variable
//         while(dividend>=divisor){
//             dividend -= divisor;
//             quotient++;
//         }
        
//         // Return the value of quotient with the appropriate sign.
//         return quotient * sign;
//     }
// };



///----------------------------SECOND APPROACH--------------------------
//So 20/3 = 3 + 6 + 12 + (24, ignore) (curr result is 2^(3-1)=4, 3 here is number of iterations...)
// left over sum, 20-12 = 8, and we repeat the process...
// So 8/3 = 3 + 6 + (12, ignore) (this time result is 2^(2-1)=2, 2 here is number of iterations...)
// left over sum, 8-6 = 2, since 2 is less than 3, we terminate the process...
//Hence final result is 4+2 = 6


class Solution {  // TC:O(logn) SC:O(1)
public:
    int divide(int dividend, int divisor) {
        //Handling corner cases
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        if(dividend == INT_MIN and divisor == 1) return INT_MIN;
        
        //converting dividend and divisor into POSITIVE values
        long int dd = abs(dividend) , dv = abs(divisor);
        
        int ans = 0;
        while(dv <= dd){
            long int a = dv , iterations = 1;
            while(a <= dd-a){
                a += a;
                iterations += iterations;
            }
            
            ans = ans+iterations;
            dd = dd-a;  // updating the dividend value
        }
        
        //If the either of the DIVIDEND OR DIVISOR is Negative our Answer will be Negative
        if( (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0) ){
            return -ans;
        }
        else{
            return ans;
        }
    }
};

