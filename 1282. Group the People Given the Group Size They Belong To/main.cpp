class Solution {//TC:O(N)  SC:O(N^2)
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>map;
        for(int i = 0;i<groupSizes.size();i++) {
            map[groupSizes[i]].push_back(i);
        }
        
        for(auto [a,b]:map) {
            int j = 0;
                while(j < b.size()) {
                    vector<int>temp;
                    for(int x = 0;x<a;x++){
                        temp.push_back(b[j]);
                        j++;
                    }
                    ans.push_back(temp);
                }
        }
        return ans;
    }
};
