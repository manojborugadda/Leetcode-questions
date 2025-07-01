class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        int n = items.size();
        vector<int>ans;
        for(int i = 1;i<n;i++) {
            items[i][1] = max(items[i-1][1],items[i][1]);
        }
      //Use ''''upper_bound''' to efficiently find the first item with a price greater than the query. Then, access the previous item to get the maximum beauty for prices ≤ the query.
        for(int query : queries) {
            auto it = upper_bound(items.begin(),items.end(),vector<int>{query+1,0});
            if(it == items.begin()) {
                ans.push_back(0);
            }else {
                ans.push_back((*(it - 1))[1]);
            }
        }
        return ans;
    }
};

/***
sorting items -- mlogm , where 'm' is the number of items
Processing each query using upper_bound: nlogm , where 'n' is the number of queries
TC:O((m+n) logm)
****/
