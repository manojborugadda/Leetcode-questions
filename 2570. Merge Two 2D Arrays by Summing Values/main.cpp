class Solution {//TC:O(logN)  SC:O(N)
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int>map;
        vector<vector<int>>ans;
        int n = nums1.size();
        for(int i = 0;i<n;i++) {
            map[nums1[i][0]] = nums1[i][1];
        }
        for(int i = 0;i<nums2.size();i++) {
            if(map.find(nums2[i][0]) != map.end()) {
                map[nums2[i][0]] += nums2[i][1];
            }else {
                map[nums2[i][0]] = nums2[i][1];
            }
        }
        for(auto [a,b] : map) {
            ans.push_back({a,b});
        }  
        sort(ans.begin(),ans.end());  
        return ans;
    }
};
