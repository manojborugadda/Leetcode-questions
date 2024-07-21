class Solution {//TC:O(N) SC:O(1)
public:
    int maxOperations(string s) {
        int count = 0 , ans = 0;
        for(int i = 0;i<s.length();i++) {
            if(s[i] == '1' and s[i+1] == '0') {//cutting the '11111.....1' count before starting '00000.....0' block
                count++;
                ans += count;
            }else if(s[i] == '1' and s[i+1] == '1') {//counting in the'1111' block
                count++;
            }
        }
        return ans;
    }
};
