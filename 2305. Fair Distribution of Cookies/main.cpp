class Solution {///TC;O(N*K)   SC:O(N) + O(K) auxiliary stack space in recursion.
private:
    void backtracking(int index,vector<int>& cookies,vector<int>& child,int k , int &ans) {
        int n = cookies.size();
        if(index == n) {
            int maxi = INT_MIN;
            for(auto it : child) {
                maxi = max(it,maxi); // here we gets the MAXIMUM value out of K subset sum
            }
            ans = min(ans,maxi);
            return;
        }
        for(int i = 0;i<k;i++) {
            child[i] += cookies[index];
            backtracking(index+1,cookies,child,k,ans);
            child[i] -= cookies[index];
        }
    }

public: //using backtracking we have solved this 
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        int ans = INT_MAX;
        backtracking(0,cookies,child,k,ans);
        return ans;
    }
};
