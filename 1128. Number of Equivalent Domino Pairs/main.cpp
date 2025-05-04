class Solution {///TC:O(N)+O(K) -- k is the size of map and N is the size of dominoes
public:             //SC:O(k)
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>map;
        for(int i = 0;i<dominoes.size();i++) {
            int val = dominoes[i][0] < dominoes[i][1] ? (dominoes[i][0]*10 + dominoes[i][1]) : (dominoes[i][1]*10 + dominoes[i][0]);
            map[val]++;
        }
        int ans = 0;

        for(auto [a,b] : map) {
            if(b > 1) {//if any freq of value is morethan 1 its means we can have multiple combinations of pairs
                ans +=(b*(b-1))/2; // no of pairs --> nC2 formula
            }
        }
        return ans;
    }
};
