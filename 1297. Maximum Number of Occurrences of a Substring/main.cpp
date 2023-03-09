class Solution {//TC:O(N) SC:O(N)
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        int ans = 0;
        map<string,int>map;
        for(int i = 0;i<= n - minSize;i++) {
            map[s.substr(i,minSize)]++;
        }

        for(auto [x,y]:map) {
            set<char>substring(x.begin(),x.end());//for unique characters in the substring
            if(substring.size() <= maxLetters) {
                ans = max(ans,y);
            }
        }
        return ans;
    }
};
