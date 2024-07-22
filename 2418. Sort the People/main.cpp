class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
     vector<string>ans;
     vector<pair<int,string>>people;
     for(int i = 0;i<names.size();i++) {
        people.push_back({heights[i],names[i]});
     } 
     sort(begin(people),end(people),greater<>());
     for(auto vec: people) {
        ans.push_back(vec.second);
     }  
     return ans;
    }
};
