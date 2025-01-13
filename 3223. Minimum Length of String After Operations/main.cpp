class Solution {//TC:O(N)  SC:O(1)
public:
    int minimumLength(string s) {
        vector<int>count(26,0);
        int len = 0;
        for(auto ch: s) {
            count[ch-'a']++;
        }
        for(auto num : count) {
            if(num ==  0) continue;
            len += (num % 2 == 0) ? 2 : 1;
        }
        return len;
    }
};
