class Solution { ///TC:O(NlogN) SC:O(N)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ans;//answer vector
        
        for(int i = 0;i<arr.size();i++) {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
      sort(ans.begin(),ans.end());
        return ans;
    }
};