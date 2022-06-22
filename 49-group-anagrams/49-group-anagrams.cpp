class Solution { 
                //Time Complexcity : O(n.klog(k)) where k is the length of string and n is    total no. of strings
                //Space Complexcity : O(n) if none of the strings are anagram
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>map;
        for(auto x : strs){
            string temp  = x;
            sort(x.begin(),x.end());
            map[x].push_back(temp);
        }
        
        for(auto x : map){
            ans.push_back(x.second);
        }
        return ans;
    }
};

// sorted KEY----------VALUE
//      aet----- [eat ,tea ,ate]
//      ant----- [tan , nat]
//      abt-----[bat]