class Solution { ///TC:O(Nlogn+N) SC:O(1)
public:
    int minMoves2(vector<int>& nums) {
        int moves = 0;// minimum number of moves required to make all array elements equal
        int median;
        int n = nums.size();
        sort(nums.begin(),nums.end());// we have to sort for finding the MEDIAN
/*
Because the median element will lie between the shortest range in the middle and taking the difference from the median will give the minimum possible value for this shortest range.*/

        //Finding the median
        
        if(n%2==0){ // if the size of Vector is EVEN
             median = ( nums[n/2-1] + nums[n/2] )/2;  // average of 2 middle elements
        }else{ // if size of the vector is ODD
            median = nums[n/2];
        }
       
       
        for(auto x:nums){ 
            moves += abs(x-median);
        }
        
        return moves;
        
        
    }
};