class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) 
    {
         int n = num.size();
        vector<int>ans; /// storing the answer--------
         for(int i=n-1;i>=0;i--){
            k = k+num[i];
             ans.push_back(k%10);
             k /= 10;
         }
        while(k>0){
            ans.push_back(k%10);
            k /= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};