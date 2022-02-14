class Solution {
public:
    int reverse(int x)
    {
         // long in = 3456789;
    long out = 0;
    while(x)
    {
         if(out > INT_MAX/10 || out < INT_MIN/10){
                return 0;
         }
        out *= 10;
        out += x % 10;
        x /= 10;
    }
        if(x < 0){
            return -out;
        }
    
    return out ;
    }
};