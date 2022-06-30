class Solution { //TC:O(N) SC:O(1)
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int result = 0; // minimum no of moves  count
        int minimum = INT_MAX;
        for(int i = 0;i<n;i++){ // finding the minimum element in the given array. It takes O(N) time
            if(nums[i] < minimum){
                minimum = nums[i];
            }
        }
        
        for(int i = 0;i<n;i++){ //adding the differences between the minimum element and each element 
            result = result + nums[i] - minimum;
        }
        return result;
    }
    
};