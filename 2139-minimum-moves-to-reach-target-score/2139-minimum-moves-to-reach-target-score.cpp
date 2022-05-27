class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
      /// we are solving this question in Reverse direction
        while(target != 1)
        {
            if(target%2==0){ // if the target number is EVEN
                if(maxDoubles > 0){  /// it means we can use dividing operation
                    target = target/2;  
                    maxDoubles--;
                    count++;
                }
                else{ // if the maxDoubles is fully used and equal to 0
                    count += target -1; //hard coded this LOGIC for not getting the TLE(Time Limit Exceed)
                    target = 1;
                }
            }
            else{  /// If the number is ODD
                target = target-1;
                count++;
            }
        }
        return count;
    }
};