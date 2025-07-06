class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>map;
        for(int i:arr) {
            map[i]++;
        }
        int ans = -1;
        for(auto [key,val] : map) {
            if(key == val) {
                ans  = max(ans,key);
            }
        }
        return ans;
    }
};
