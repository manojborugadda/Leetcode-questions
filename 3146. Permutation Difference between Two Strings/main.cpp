class Solution {
public:
    int findPermutationDifference(string s, string t) {
     unordered_map<char,int>m1,m2;
        for(int i =0 ;i<s.length();i++) {
            m1[s[i]] = i;
        }
        for(int i =0 ;i<t.length();i++) {
            m2[t[i]] = i;
        }
        int ans = 0;
        for(auto c:s){ 
            ans += abs(m1[c] - m2[c]);
        }
        return ans;
    }
};
