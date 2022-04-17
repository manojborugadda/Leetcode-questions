class Solution { //TC:O(N) // space complexity : O(1) [because hasmap size is always 3]
public:
    int numberOfSubstrings(string s) {
        int left = 0, right = 0, end = s.size()-1;
        int count  = 0;
        unordered_map<char,int>mp;
        
        while(right != s.size()){
            mp[s[right]] += 1;
            
            while(mp['a'] and mp['b'] and mp['c']){
                count += 1+(end - right);
                mp[s[left]] -= 1;
                left++;
            }
             right++;
        }
        return count;
    }
};