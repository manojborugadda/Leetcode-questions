class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s==goal){
            unordered_map<char,int>mymap;
            for(auto ch:s){
                mymap[ch]++;
            }
            if(mymap.size()<s.length()){
                return true;
            }
            return false;
        }
        vector<int>v;
        for(int i=0;i<s.length();i++){
            if(s[i]!=goal[i]){
                v.push_back(i);
            }
        }
        if(v.size()==2 && s[v[0]]==goal[v[1]] && s[v[1]]==goal[v[0]] ){
            return true;
        }
        return false;
    }
};