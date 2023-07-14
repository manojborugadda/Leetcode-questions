class Solution { //TC:O(n)  SC:O(N)
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>map;
        int ans = 0;
        int n = arr.size();
        for(int num : arr) {
            if(map.find(num-difference) != map.end()) {
                map[num] = map[num-difference] + 1;
            }else {
                map[num] = 1;
            }
            ans = max(ans,map[num]);
        }
        return ans;
    }
};
