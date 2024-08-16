class Solution {//TC:O(N)  SC:O(1)
public:
    int maxDistance(vector<vector<int>>& arr) {
        int mini = arr[0].front();
        int maxi = arr[0].back();
        int ans = 0;
        for(int i = 1;i<arr.size();i++) {
            ans = max(ans,abs(arr[i].back() - mini));
            ans = max(ans,abs(maxi - arr[i].front()));

            //updating the global variables mini,maxi
            mini = min(mini,arr[i].front());
            maxi = max(maxi,arr[i].back());
        }
        return ans;
    }
};

/*** we need to get the maximum "maxi" and minimum "mini" of every array and \
get the maximum difference of those \
by getting the abosulute difference of mininum element of current array and maxi elment \
and absolute difference of maximum element of current array and mini elment 
**/
