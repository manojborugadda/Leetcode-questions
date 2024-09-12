class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st(allowed.begin(),allowed.end());
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            bool ispresent=true;
            for(int j=0;j<temp.length();j++){
                if(st.find(temp[j])==st.end()){
                    ispresent=false;break;
                }
            }
            if(ispresent)cnt++;
        }
        return cnt;
        
    }
};
/**
Time complexity: O(n∗m) where n is the number of words, and m is the average length of each word.

Space complexity: O(k) , where k is the length of the allowed string, since we are storing characters in a set.
*/
