class Solution {  //TC:O(N)  SC:O(N)
public:
    vector<long long> getDistances(vector<int>& arr) {
        int  n = arr.size();
        unordered_map<long long,vector<long long>>map;
        vector<long long>prefix(n,0),suffix(n,0),ans(n,0);
        
        
        //storing indices of the same elements in the HASHMAP
        for(int i = 0;i<n;i++) {
            map[arr[i]].push_back(i);
        }
        
        //  prefix will store the sum of "absolute differences" from the starting index of "current element" to the current index.
        for(auto [x,y] : map) {
            for(int i = 1;i<y.size();i++) {
                prefix[y[i]] = prefix[y[i-1]] + i*(y[i] - y[i-1]);
            }
        }
        
        //suffix will store the sum of absolute diff. from the ending index of current element to the current index.
        for(auto [x,y] : map) {
            for(int i = y.size()-2;i >= 0;i--) {
                suffix[y[i]] = suffix[y[i+1]] + (y.size()-1-i) * (y[i+1]-y[i]);
            }
        }
        
        //adding the PREFIX[i] and SUFFIX[i] for the particular ans[i]
        for(int i = 0;i<n;i++) {
            ans[i] += prefix[i] + suffix[i];
        }
        return ans;
    }
};