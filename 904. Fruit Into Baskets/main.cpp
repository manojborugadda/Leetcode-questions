class Solution {//TC:O(N)  SC:O(1)
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>map;
        int i = 0,j = 0;
        int ans = 0;
        while(i < n) {
            map[fruits[i]]++;
            while(map.size() >2) {
                map[fruits[j]]--;
                if(map[fruits[j]] == 0) {
                    map.erase(fruits[j]);
                }
                j++;
            }
            ans = max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};
