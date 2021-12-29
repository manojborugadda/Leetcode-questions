class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1)
            return 1;
        int min_indx = min_element(nums.begin(),nums.end()) - nums.begin();
        int max_indx = max_element(nums.begin(),nums.end()) - nums.begin();
        
        /*
        
         int y = max(minInd, maxInd)
         int x = min(minInd, maxInd)
        Case 1 : Removing both element from front 
                 max(minInd, maxInd)
        Case 2 : Removing both element from Back
                 n - min(minInd, maxInd)
        Case 3 : Removing One element from front and One element from the Back
                 min(minInd,maxInd) + n - max(maxInd, minInd) + 1

        Answer = min(Case 1, Case 2, Case 3);
    */
        
        int y = max(min_indx,max_indx);
        int x = min(min_indx,max_indx);
        int ans = min({y+1,n-x, n-(y-x-1)});
        return ans;
    }
};
