class Solution {//TC:O(N)  SC:O(1)
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0 , one = 0;
        for(int i = 0;i<s.size();i++) {
            if(s[i]=='1') {
                one++;
            }else {
                ans  = min(ans+1,one);
            }
        }
        return ans;
    }
};
