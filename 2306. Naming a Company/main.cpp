class Solution {//TC:O(N)  SC:O(N)
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        unordered_set<string>set(begin(ideas),end(ideas));
        unordered_map<char,unordered_map<char,int>>map;
        for(auto &str : set) {
            string s = str;
            char prev = s[0];
            for(char c = 'a';c<='z';c++) {
                s[0] = c;
                if(set.find(s) == set.end()) {
                    map[c][prev]++;
                }
            }
        }

        for(auto &str : set) {
            string s = str;
            char prev = s[0];
            for(char c = 'a';c<='z';c++) {
                s[0] = c;
                if(set.find(s) == set.end()) {
                    ans += map[prev][c];
                }
            }
        }
        return ans;
    }
};
