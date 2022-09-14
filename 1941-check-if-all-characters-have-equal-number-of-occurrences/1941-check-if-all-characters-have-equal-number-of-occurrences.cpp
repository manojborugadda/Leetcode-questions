class Solution { //TC:O(N) SC:O(N)
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>map;
        for(auto i:s){
            map[i]++;
        }
        
        int temp = map[s[0]];
        for(auto [key,val] : map){
            if(temp != val){
                return false;
            }
        }
        return true;
    }
};