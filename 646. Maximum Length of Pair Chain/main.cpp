class Solution {//TC:O(N)
public:
    static bool comp(vector<int>&a,vector<int>&b) {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int ans =1;
        sort(pairs.begin() , pairs.end(),comp);
        int end = pairs[0][1];
        for(int i = 1;i<n;i++) {
            if(pairs[i][0] > end) {
                ans++;
                end = pairs[i][1];
            }
        }
        return ans;
    }
};
//For dp approach, it's almost similar to Longest Increasing Subsequence problem.
