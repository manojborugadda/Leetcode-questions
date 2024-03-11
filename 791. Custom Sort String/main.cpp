class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char,int>map;
        for(char ch: s) {
            map[ch]++;
        }
        for(char ch:order) {
            if(map.count(ch)) {
                int freq = map[ch];
                while(freq--) {
                    ans+= ch;
                }
                map[ch] = 0;
            }
        }

        for(auto [ch,freq] : map) {
            if(freq != 0) {
                ans+= string(freq,ch);
            }
        }
        
        return ans;
    }
};
