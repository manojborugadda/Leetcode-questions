class Solution {//TC:O(N)  SC;O(1)
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int diff = arr[1] - arr[0];
        for(int i = 2;i<arr.size();i++) {
            if(arr[i]-arr[i-1] != diff) {
                return false;
            }
        }
        return true;
    }
};
