class Solution {
public:
    bool stoneGameIX(vector<int>& stones)
    {
        vector<int>c(3);
        for(auto s:stones){
            ++c[s%3];
        }
        if(c[0]%2==0){
            return(min(c[1],c[2])) > 0;
        }
        else
        {
            return abs(c[1]-c[2]) >2;
        }
        
    }
};