class Solution { //TC:O(nLogn) + mLogm  SC:O(n) , where m is the size of queries
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int>ans;
        vector<int>prefix(n,0);
        sort(begin(nums),end(nums)); //TC:O(nlogn)
        
        //first element of PREFIX array always be the First element of the nums
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = 0;i<queries.size();i++) {
            int query = queries[i];
        //we get the size of the maximum size of a subsequence by 
        //differnce between index we got by searching using UPPER_BOUND and prefix vector 0th index
        //upperbound takes T:O(mlogm)
            ans.push_back(upper_bound( begin(prefix),end(prefix),query) - begin(prefix));
        }
        return ans;
    }
};
