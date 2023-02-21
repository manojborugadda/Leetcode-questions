class Solution {//TC:O(N) SC:O(N)
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto x:nums) {
            map[x]++;
        }
        for(auto x:map) {
            if(x.second < 2){
                return x.first;
            }
        }
        return 0;
    }
};
