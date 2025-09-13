```
class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26]={0};
        string vowels="aeiou";
        for(char ch : s){
            freq[ch-'a']++;
        }
        int max_v=0;
        int max_c=0;
        for(int i=0;i<26;i++){
            char ch = 'a'+i;
            if(vowels.find(ch)!=string::npos){
                max_v=max(max_v,freq[i]);
            }
            else{
                max_c=max(max_c,freq[i]);
            }
        }
        return max_v+max_c;
    }
};
```



https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/solutions/6733044/easy-c-soln-with-detail-explanation-beats-100/?envType=daily-question&envId=2025-09-13
