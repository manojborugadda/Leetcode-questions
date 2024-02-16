class Solution {//TC:O(NLOGN)  SC:O(N)
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
       typedef pair<int,int> p;
       priority_queue<p, vector<p>, greater<p>> pq; 
       unordered_map<int,int>map;
       for(int i = 0;i<arr.size();i++) {
           map[arr[i]]++;
       } 
       for(auto [a,b] : map) {
           pq.push({b,a});
       }

        while( !pq.empty() and k > 0) {
            auto a = pq.top();
            if(pq.top().first <= k) {
                k -= pq.top().first;
                pq.pop();
            }else {
                k -= pq.top().first;
            }
        }
        return pq.size();
    }
};

/**
we need to remove the elements which has small frequency 

*/
