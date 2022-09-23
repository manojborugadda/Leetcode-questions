class Solution {  //TC:O(N)  SC:O(1)
public:
    
    int numberOfBits(int n) {
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long ans  = 0 , MOD = 1e9+7;
        for(int i = 1;i<n+1;i++) {
            int len = numberOfBits(i);
            //here we left shift the previous Binary didgit by length of the current Binary number
            //and add it to the current Binary number
            //for example adding 1 to 2
            //(Binary number is 1 for 1 ) , leftshifted 1 by 2 ZEORES and add the 10
            // 2 ---- Binary is 10 which is length of 2, so 100 + 10  = 110
            ans = ((ans<<len)%MOD+i)%MOD;
        }
        return ans;
    }
};