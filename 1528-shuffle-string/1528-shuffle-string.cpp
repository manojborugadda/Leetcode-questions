class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
     
        vector<pair<int,char>>v;
for(int i=0;i<s.size();i++)
{
v.push_back(make_pair(indices[i],s[i]));
}
string z="";
sort(v.begin(),v.end());
for(int i=0;i<v.size();i++)
{
z.push_back(v[i].second);
}
return z;
        
        
    }
};