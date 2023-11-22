class Solution {//TC:O(N^2*NLOGN)  SC:O(N)
public:
    typedef pair<pair<int,int>,int> pi;
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<pi,vector<pi>,greater<pi>>pq;//min heap
        for(int i = 0;i<nums.size();i++) {
            for(int j = 0;j<nums[i].size();j++) {
                pq.push({ {i+j,j}, nums[i][j] });//pushing in  { {diagonal sum , column} , value }
            }//it will get sorted on the diagonal sum and Column number basis
        }

        vector<int>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
