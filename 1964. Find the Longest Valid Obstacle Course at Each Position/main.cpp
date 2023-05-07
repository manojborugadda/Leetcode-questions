class Solution {//TC:O(nlogn) SC:O(N)
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans, nums;
        for(auto obstacle : obstacles) {
            if(nums.empty() or nums.back() <= obstacle) {
                nums.push_back(obstacle);
                ans.push_back(nums.size());
            }else {
                int index = findIndex(nums,obstacle);
                nums[index] = obstacle;
                ans.push_back(index+1);
            }
        }
        return ans;
    }


//finding the index of the number
    int findIndex(vector<int>&arr,int target) {//logn time
        return upper_bound( begin(arr),end(arr),target ) - begin(arr);
    }
};
