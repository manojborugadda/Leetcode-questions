//SLIDING WINDOW problem using SET // TWO POINTER APPROACH


class Solution {  // TC:O(N) SC:O(N)
public:
    // it is a variant of Longest Substring Without Repeating Characters problem 
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        set<int>s; // we are using SET here for maintaining the unique elements in subarray
        int right = 0 , left = 0 , ans = 0 , currsum = 0;
        while(right<n)
        {
            if(s.count(nums[right])==0){ // if the set doesnot contain current element
                currsum  += nums[right];  // we add to the currsum
                ans = max(ans,currsum); // update the ans
                s.insert(nums[right]);  // insert into the SET
                right++;
            }else{     //if we find the element already present in the SET
                currsum  -= nums[left];//subtract that elements from sum
                s.erase(nums[left]);// we delete or remove that
                left++;
            }
        }
        return ans;
    }
};