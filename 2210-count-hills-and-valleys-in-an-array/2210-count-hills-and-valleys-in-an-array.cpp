class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int>v; // new vector which will not have duplicates
        v.push_back(nums[0]);  // inserting first element

        //Note that for an index to be part of a hill or valley, it must have a "non-equal neighbor" on both the left and right of the index.
        // it means no duplicates should be there
        
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            v.push_back(nums[i]);
        }
    }
    int count=0;  // Number of Hills and Valleys
    for(int i=1;i<v.size()-1;i++)
    {
        if((v[i]>v[i-1] and v[i]>v[i+1]) or (v[i]<v[i-1] and v[i]<v[i+1])){
            count++;
        }
    }
        
    return count;
        
    }
};