class Solution {
public:
    char findTheDifference(string s, string t) 
    {
          unordered_map<char,int>m1,m2;
            for(auto x :s){
                m1[x]++;
            }
        for(auto k:t){
            m2[k]++;
        }
        char unique;
        for(auto s:t){
            if(m1[s] < m2[s]){
                unique = s;
                break;
            }
        }
        
        return unique;
    }
};