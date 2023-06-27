class Solution { //TC:O(N)  SC:O(N)  //we are using extra space
public://               using HASHMAPS
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>map;
        //checking if any element is repeated  and if YES we push that into the ans vector
        for(int i:nums) {
            if(map.find(i)!=map.end()) ans.push_back(i); 
            map[i]++;
        }
        
    //checking for the missing element using HASHMAP and if we got that we pushed into the vector
        for(int i = 1;i<=n;i++) {
            if(map.find(i)==map.end()) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
