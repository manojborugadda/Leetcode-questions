class Solution { ///TC:O(nlogn) SC:O(1)
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1;i<words.size();i++){
            string s1 = words[i] , s2 = words[i-1];
                if(checkAnagram(s1,s2)){
                    words.erase(words.begin()+i);//deleting the words[i] if we found the anagram
                    i--;
                }
        }
        return words;
    }
    //checking if Two Strings are ANAGRAMS or NOT
    bool checkAnagram(string a,string b){
        if(a.length()!= b.length()) return false;
        if(a==b) return true;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b) return true;
        return false;
    }
};