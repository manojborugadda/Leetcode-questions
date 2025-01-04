class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,vector<int>>map;
        int n = s.length();
        for(int i =0;i<n;i++) {
            map[s[i]].push_back(i);
        }
        set<char>st;
        int ans = 0;
        for(auto [a,b] : map) {
            int firstIdx = b.front();
            int lastIdx = b.back();
            if(b.size() > 1) {
                for(int i = firstIdx+1;i<lastIdx;i++) {
                st.insert(s[i]);
            }
                ans += st.size();
                st.clear();
            }
        }
        return ans;
    }
};
