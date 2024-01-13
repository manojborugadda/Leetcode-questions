class Solution {//TC:O(N)  SC:O(N)
public:
    int minSteps(string s, string t) {
        int count = 0;
        unordered_map<char,int>map1,map2;
        for(auto ch : s) {
            map1[ch]++;
        }
        for(auto ch:t) {
            map2[ch]++;
        }

        for(auto [a,b] : map1) {
            if(map2.find(a) != map2.end()) {
                if(b - map2[a] > 0) {//if the freq of element in mp1 is greater than freq of the same element in mp2
                    count += b - map2[a];
                }
            }else {
                count += b;
            }
        }
        return count;
    }
};
