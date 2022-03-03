class Solution {
public:
    //vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        bool check(vector<int>&v){
        sort(v.begin(),v.end());
        int diff=v[1]-v[0];
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]-v[i]!=diff)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& n, vector<int>& l, vector<int>& r) {
        int a=l.size();  // we can take r.size() also
        vector<bool>bool1; // answer vector------
        for(int i=0;i<a;i++){
            vector<int>v; // vector storing the sequences
            for(int j=l[i];j<=r[i];j++){  // we want the array of indexes from l[i] in nums to r[i] in nums
                v.push_back(n[j]);
            }
            bool1.push_back(check(v)); // checking if s[i+1] - s[i] == s[1] - s[0] 
        }
        return bool1;
    }
};