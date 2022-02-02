class Solution {
public:
        vector<int> findAnagrams(string s, string p) {
        vector<int> v,freq_s(26), window(26);
        int ps = p.size();
        if(ps > s.size()) return v;
        for(int i = 0; i < ps; i++) {
            freq_s[s[i]-'a']++;
            window[p[i]-'a']++;
        }
        if(freq_s == window) v.push_back(0);  // this is upto the first slide of length 3 and we are checking 
            
        for(int i = 1; i < s.size()-ps+1; i++) { 
            freq_s[s[i-1]-'a']--;  // decrementing the last element in the 
            freq_s[s[i+ps-1]-'a']++;  // incrementing for latest character
            if(freq_s == window) v.push_back(i);
        }
        return v;
    }
};