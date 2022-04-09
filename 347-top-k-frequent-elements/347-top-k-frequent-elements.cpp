class Solution {      // TC:O(NlogN)          SC:O(N)
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans; // answer vector
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;   // calculating the frequency of the elements
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(auto y:mp){
            pq.push(make_pair(y.second,y.first)); // Pushing "frequency" and "element" order into the priority queue for our problem convenience
        }
        
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};