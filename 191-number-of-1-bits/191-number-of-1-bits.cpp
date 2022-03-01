class Solution {
public:
    // int hammingWeight(uint32_t n){
    //     return __builtin_popcount(n);
    // }
    
    int hammingWeight(uint32_t n) {
        int count =0;
        while (n!=0){
            //Checking  last bit
        if(n&1){//Binary AND checking the if the number is odd or not. since odd numbers will have LSB of 1 
                count++;
            }
            n = n>>1; // n/2^1;
        }
        return count;
    }
		
};