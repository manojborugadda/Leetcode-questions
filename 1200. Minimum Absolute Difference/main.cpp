class Solution {//TC:O(nlogn)  SC:O(N)
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        vector<vector<int>>ans;
        sort(begin(arr),end(arr)); //O(logn)
        
        //finding the minAbsDifference value
        int minAbsDiff = INT_MAX;
        for(int i  = 1;i<n;i++) {
            minAbsDiff = min(minAbsDiff,arr[i] - arr[i-1]);
        }

        //aggregating the pairs which have difference equal to "minAbsDiff"
        for(int i =1;i< n;i++) {
            if((arr[i] - arr[i-1]) == minAbsDiff) {
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};
