class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
       unordered_map<int,int> mp;
        for(auto c:candyType){
            mp[c]++;
        }
        int re=candyType.size()/2;
        return re>=mp.size() ? mp.size() : re;
    }
    
};