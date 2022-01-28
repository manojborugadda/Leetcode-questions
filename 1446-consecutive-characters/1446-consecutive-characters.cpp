class Solution {
public:
    int maxPower(string s) {
        int res=1,c=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1])c++;
            else res=max(res,c),c=1;
        }
        return max(res,c);
    }
};