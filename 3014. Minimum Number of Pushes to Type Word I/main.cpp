class Solution {//TC:O(nlogn+n) SC:O(n)
public:
    int minimumPushes(string word) {
         int ans = 0;
        vector<int>freq(26,0);
        for(auto ch: word) {
           freq[ch-'a']++;
        }
        sort(begin(freq),end(freq),greater<int>());//sorting in descending order
        for(int i = 0;i<26;i++) {
            //First 8 frequncy count should use the single key press then next 8 double key press and the next 8 will hit 3 key press and so on.
            ans += freq[i] *  ( (i/8) + 1 );//it will work for duplicate or unique characters in string
        }
       return ans;
    }
};
