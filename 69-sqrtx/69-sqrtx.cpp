class Solution {
public:
    int mySqrt(int x) {
       long long int low = 0, high = x, mid;
        
        while(low<=high){
            mid = (low+high)/2;
            
            if(mid*mid==x) return mid;
            else if(mid*mid > x)  high=mid-1;
            else low=mid+1;   
        }
        return high;
    }
};