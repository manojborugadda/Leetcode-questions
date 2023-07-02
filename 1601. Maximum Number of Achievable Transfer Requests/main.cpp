class Solution {
public:
    int ans = 0;
    void backtrack(vector<vector<int>>& requests,int index,vector<int>&transfers,int count) {
        if(index == requests.size()) {
            for(auto change : transfers) {
                if(change != 0) return;
            }
            ans = max(ans,count); //if all elements in the transfers are EQUAL to ZERO 
            return;
        }

        int from = requests[index][0];
        int to = requests[index][1];

        //Option 1 ---- consider the current request
        transfers[from]--;
        transfers[to]++;
        backtrack(requests,index+1,transfers,count+1);

        //backtracking happening here
        transfers[from]++;
        transfers[to]--;
        //Option 2 ----- DO NOT  consider the current request
        backtrack(requests,index+1,transfers,count);
    }


    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>transfers(n);
        backtrack(requests,0,transfers,0);
        return ans;
    }
};
