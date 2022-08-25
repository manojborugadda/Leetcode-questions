/*
Alex can sit in between 2 persons
Alex can sit at FAR left
Alex can sit at FAR right

case1: find the distance between the 2 people and find the MID ------- [1,0,0,0,1,0,1]
case2 : find the first person sitting from LEFT --------- [0,0,0,0,1]
case 3: find the first person sitting from RIGHT --- example : [1,0,0,0]

*/


class Solution {  //TC:O(N)  SC:O(1)
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.size() == 0) return 0;
        int result = 0 , val = 0 , n = seats.size();
        
        //case 1:
        for(int i = 0;i<seats.size();i++) {
            if(seats[i] == 1){
                val = 0;
            }else{
                val++;
                result = max(result,(val+1)/2);
            }
        }
        
        //case 2:
        for(int i = 0;i<seats.size();i++) {
            if(seats[i] == 1){
                result = max(result,i);
                break;
            }
        }
        
        //case 3:
        for(int i = seats.size()-1;i>=0;i--) {
            if(seats[i] == 1){
                result = max(result,n-1-i);
                break;
            }
        }
        
        return result;
    }
};