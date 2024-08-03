class Solution {//TC:O(N) SC:O(2N)
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target == arr) return true;
        unordered_map<int,int>map,tmap;
        for(auto num : arr) {
            map[num]++;
        }
        for(auto num : target) {
            tmap[num]++;
        }
        for(auto num : target) {
            if(map[num] != tmap[num]) {
                return false;
            }
        }
        return true;
    }
};
