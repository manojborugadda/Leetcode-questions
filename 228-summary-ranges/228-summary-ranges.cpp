// Time Complexity --> O(n) // where n is the length of the array 
// Space Complexity --> O(1) // we are not using anything extra from our side


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
         vector<string>ans; // answer vector------
        for(int i = 0;i<n;i++){
        int start = nums[i];
            while(i+1 < n and nums[i+1]==nums[i]+1){
                i++;
            }
            
            if(start!=nums[i]){              //that means we got our range more than one element
                ans.push_back("" + to_string(start)+ "->" + to_string(nums[i]));
            }
            else{              //we got only one element as range
                ans.push_back(""+to_string(start));
            }
        }
    return ans;
  }
};