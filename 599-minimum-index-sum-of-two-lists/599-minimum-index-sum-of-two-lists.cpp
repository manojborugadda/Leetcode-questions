class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sum = INT_MAX;
        vector<string> ans; // answer vector
        unordered_map<string,int>map;
        
        for(int i = 0;i<list1.size();i++){ //insert list1 into map
            map[list1[i]] = i;
        }
        
        for(int i = 0;i<list2.size();i++) //traverse list 2
        {
            if(map.find(list2[i])!=map.end()) //search for each element in map and if found
             {   
                if( map[list2[i]] + i < sum ){ //check sum of index less than sum 
                    ans.clear();  //if TRUE ans is cleared as lesser sum found
                    ans.push_back(list2[i]); //value of index i of list2 is added to ans
                    sum = map[list2[i]]+i;  //update sum
                }
                else if(map[list2[i]] + i == sum){//if equal then this value is also added to the ans
                    ans.push_back(list2[i]);
                }
            }
        }
        
        return ans;
    }
};