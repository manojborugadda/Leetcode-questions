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

//https://leetcode.com/problems/find-the-difference/solutions/911889/concise-100-faster-with-explanation/?envType=daily-question&envId=2023-09-25
