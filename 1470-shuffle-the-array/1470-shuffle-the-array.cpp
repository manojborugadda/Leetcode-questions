class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> vec;
        int a=0;
        int b=n;
        n = 2*n;
        while(a<n && b<n){
            vec.push_back(nums[a++]);
            vec.push_back(nums[b++]);
        }
        return vec;
    }
};