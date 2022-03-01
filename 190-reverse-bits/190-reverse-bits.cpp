class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t revN = 0;
        
        // Reverse n from LSB to MSB
        for(short i = 0 ; i < 32 ; i++){
            
            revN <<= 1;
            
            revN |= (n & 1);
            
            n >>= 1;
        }
        
        return revN;
        
    }
};