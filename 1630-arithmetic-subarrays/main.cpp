class Solution {//TC:O(N^2) SC:O(N)
public:
    bool isArithmeticSequence(vector<int>&temp) {
        sort(begin(temp),end(temp));
        int diff = temp[1] - temp[0];
        for(int i = 2;i<temp.size();i++) {
            if(temp[i] - temp[i-1] != diff) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
       vector<bool>ans;
       for(int i = 0;i<l.size();i++) {
           //inserting into temp vector taking from the range nums[ l[i], r[i] ]
           vector<int>temp(nums.begin()+l[i] , nums.begin()+r[i]+1);
           ans.push_back( isArithmeticSequence(temp) ); 
           temp.clear();
       }
       return ans; 
    } 
};
