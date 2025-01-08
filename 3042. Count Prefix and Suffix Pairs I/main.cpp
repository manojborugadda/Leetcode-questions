class Solution {//TC;O(N^2)  SC:O(1)
public:
    bool isPrefixAndSuffix(string s1,string s2) {
        int len = s1.length();
        if(len > s2.length()) return false;
        string prefix = s2.substr(0,len);
        string suffix = s2.substr(s2.length()-len);
        if(s1 == suffix and s1 == prefix) {
            return true;
        }
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int pairs = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++) {
                if(isPrefixAndSuffix(words[i],words[j])) {
                    pairs++;
                }
            }
        }
        return pairs;
    }
};
