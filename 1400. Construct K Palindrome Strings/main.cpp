class Solution {//TC;O(N) SC:O(N)
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if(n == k) return true;
        if(n < k) return false;
        unordered_map<char,int>map;
        int count = 0;
        for(auto ch:s) {
            map[ch]++;
        }
        //Traverse the frequency map to count how many characters have an odd frequency. Each odd frequency requires its own palindrome.
        for(auto [a,b] : map) {
            if(b %2 != 0) count++;
        }
        //If the number of odd frequencies (odds) is greater than k, return false
        if(count > k) return false;
        else return true;
    }
};
